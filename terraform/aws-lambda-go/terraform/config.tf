provider "aws" {
  region  = "eu-central-1"
  profile = "jacky"
}

locals {
  lambda_handler = "golambdabin"
  name           = "jacky_go_lambda"
}

data "archive_file" "go_bin_zip" {
  type        = "zip"
  source_dir  = "../target"
  output_path = "../target/golambdabin.zip"
}

resource "aws_lambda_function" "func" {
  function_name    = "${local.name}_handler"
  handler          = local.lambda_handler
  runtime          = "go1.x"
  role             = aws_iam_role.jacky_lambda_role.arn
  filename         = data.archive_file.go_bin_zip.output_path
  source_code_hash = base64sha256(data.archive_file.go_bin_zip.output_path)
  memory_size      = 128
  timeout          = 10
  depends_on = [
    aws_iam_role_policy_attachment.attach_iam_policy_to_jacky_lambda_role
  ]
}
