#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

which zip

rm ./hello_aws_lambda.zip
zip ./hello_aws_lambda.zip ./hello_aws_lambda.py

which aws

aws lambda update-function-code \
--function-name jacky-chen-url-function-exercise \
--zip-file fileb://hello_aws_lambda.zip