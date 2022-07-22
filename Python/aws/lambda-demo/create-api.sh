#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)


aws --profile jacky apigatewayv2 create-api \
--name jacky-chen-hello-api \
--protocol-type HTTP \
--target arn:aws:lambda:eu-central-1:422686820116:function:jacky-chen-hello-lambda