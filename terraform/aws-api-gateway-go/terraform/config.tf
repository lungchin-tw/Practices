provider "aws" {
  region  = "eu-central-1"
  profile = "jacky"
}

locals {
  lambda_handler = "jacky_lambda_go_handler"
  name           = "jacky_lambda_go"
}

# var
variable "profile" {
  default = "dev"
}

################## LAMBDA ##################

# compile go
resource "null_resource" "compile" {
  triggers = {
    build_number = "${timestamp()}"
  }

  provisioner "local-exec" {
    command = "GOOS=linux GOARCH=amd64 CGO_ENABLED=0 go build -o ../target/jacky_lambda_go_handler -ldflags '-w' ../src/main.go"
  }
}

data "archive_file" "go_bin_zip" {
  type = "zip"
  # source_content_filename = "../target/golambdabin"
  source_file = "../target/jacky_lambda_go_handler"
  output_path = "../target/jacky_lambda_go_handler.zip"
  depends_on  = [null_resource.compile]
}

resource "aws_lambda_function" "func" {
  function_name    = "${local.name}_handler"
  handler          = local.lambda_handler
  runtime          = "go1.x"
  role             = aws_iam_role.jacky_lambda_role.arn
  filename         = data.archive_file.go_bin_zip.output_path
  source_code_hash = data.archive_file.go_bin_zip.output_base64sha256
  memory_size      = 128
  timeout          = 10
  depends_on = [
    aws_iam_role_policy_attachment.attach_iam_policy_to_jacky_lambda_role
  ]
}

resource "aws_lambda_permission" "allow_api" {
  statement_id  = "AllowAPIgatewayInvokation"
  action        = "lambda:InvokeFunction"
  function_name = aws_lambda_function.func.function_name
  principal     = "apigateway.amazonaws.com"
}


################## API GATEWAY ##################

resource "aws_api_gateway_rest_api" "action-api-gateway" {
  name = "${local.name}-api-gateway"
  endpoint_configuration {
    types = ["REGIONAL"]
  }
}

resource "aws_api_gateway_resource" "action" {
  rest_api_id = aws_api_gateway_rest_api.action-api-gateway.id
  parent_id   = aws_api_gateway_rest_api.action-api-gateway.root_resource_id
  path_part   = "action"
}

# POST
resource "aws_api_gateway_method" "post" {
  rest_api_id      = aws_api_gateway_rest_api.action-api-gateway.id
  resource_id      = aws_api_gateway_resource.action.id
  http_method      = "POST"
  authorization    = "NONE"
  api_key_required = false
}

# POST - Integration
resource "aws_api_gateway_integration" "integration-post" {
  rest_api_id             = aws_api_gateway_rest_api.action-api-gateway.id
  resource_id             = aws_api_gateway_resource.action.id
  http_method             = aws_api_gateway_method.post.http_method
  integration_http_method = "POST"
  type                    = "AWS_PROXY"
  uri                     = aws_lambda_function.func.invoke_arn
}

# GET
resource "aws_api_gateway_method" "get" {
  rest_api_id      = aws_api_gateway_rest_api.action-api-gateway.id
  resource_id      = aws_api_gateway_resource.action.id
  http_method      = "GET"
  authorization    = "NONE"
  api_key_required = false
}

# GET - Integration
resource "aws_api_gateway_integration" "integration-get" {
  rest_api_id             = aws_api_gateway_rest_api.action-api-gateway.id
  resource_id             = aws_api_gateway_resource.action.id
  http_method             = aws_api_gateway_method.get.http_method
  integration_http_method = "POST"
  type                    = "AWS_PROXY"
  uri                     = aws_lambda_function.func.invoke_arn
}


################## Deployment of API GATEWAY ##################

resource "aws_api_gateway_deployment" "jacky-api-gateway-deployment" {
  rest_api_id = aws_api_gateway_rest_api.action-api-gateway.id
  triggers = {
    redeployment = sha1(jsonencode(aws_api_gateway_rest_api.action-api-gateway.body))
  }

  depends_on = [aws_api_gateway_integration.integration-post]
  lifecycle {
    create_before_destroy = true
  }
}

resource "aws_api_gateway_stage" "example" {
  deployment_id = aws_api_gateway_deployment.jacky-api-gateway-deployment.id
  rest_api_id   = aws_api_gateway_rest_api.action-api-gateway.id
  stage_name    = var.profile
}


output "invoke_arn" {
  value = aws_api_gateway_deployment.jacky-api-gateway-deployment.invoke_url
}

output "stage_name" {
  value = aws_api_gateway_stage.example.stage_name
}

output "path_part" {
  value = aws_api_gateway_resource.action.path_part
}

output "complete_invoke_url" {
  value = "${aws_api_gateway_deployment.jacky-api-gateway-deployment.invoke_url}${aws_api_gateway_stage.example.stage_name}/${aws_api_gateway_resource.action.path_part}"
}
