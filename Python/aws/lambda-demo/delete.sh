#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

ROLE_NAME=jacky-chen-hello-lambda
FUNC_NAME=jacky-chen-hello-lambda

aws --profile jacky iam detach-role-policy --role-name $ROLE_NAME \
--policy-arn arn:aws:iam::aws:policy/service-role/AWSLambdaBasicExecutionRole

aws --profile jacky iam delete-role --role-name $ROLE_NAME
aws --profile jacky lambda delete-function --function-name $FUNC_NAME
aws --profile jacky apigatewayv2 delete-api --api-id 4r1ucm8pi3