
terraform {
  required_providers {
    aws = {
      source  = "hashicorp/aws"
      version = "~> 4.16"
    }
  }

  required_version = ">= 1.2.0"
}

provider "aws" {
  region  = "eu-central-1"
  profile = "jacky"
}

resource "aws_iam_role" "jacky_lambda_role" {
  name               = "jacky-lambda-role"
  assume_role_policy = <<EOF
  {
    "Version": "2012-10-17",
    "Statement": [
      {
        "Action": "sts:AssumeRole",
        "Principal": {
          "Service": "lambda.amazonaws.com"
        },
        "Effect": "Allow",
        "Sid": ""
      }
    ]
  }
  EOF
}

resource "aws_iam_policy" "jacky_lambda_iam_policy" {
  name        = "aws_iam_policy_for_terraform_aws_jacky_lambda_role"
  path        = "/"
  description = "AWS IAM Policy for managing AWS Lambda role"
  policy      = <<EOF
{
 "Version": "2012-10-17",
 "Statement": [
   {
     "Action": [
       "logs:CreateLogGroup",
       "logs:CreateLogStream",
       "logs:PutLogEvents"
     ],
     "Resource": "arn:aws:logs:*:*:*",
     "Effect": "Allow"
   }
 ]
}
EOF
}

resource "aws_iam_role_policy_attachment" "attach_iam_policy_to_jacky_lambda_role" {
  role       = aws_iam_role.jacky_lambda_role.name
  policy_arn = aws_iam_policy.jacky_lambda_iam_policy.arn

}

data "archive_file" "zip_the_python_code" {
  type        = "zip"
  source_dir  = "${path.module}/python"
  output_path = "${path.module}/python/hello-python.zip"
}

resource "aws_lambda_function" "jacky_lambda_func" {
  filename      = "${path.module}/python/hello-python.zip"
  function_name = "jacky_lambda_handler"
  role          = aws_iam_role.jacky_lambda_role.arn
  handler       = "index.lambda_handler"
  runtime       = "python3.9"
  depends_on = [
    aws_iam_role_policy_attachment.attach_iam_policy_to_jacky_lambda_role
  ]
}
