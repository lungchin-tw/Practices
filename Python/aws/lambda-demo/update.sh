#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

rm ./hello_lambda.zip
zip ./hello_lambda.zip ./lambda.py

aws --profile jacky lambda update-function-code \
--function-name jacky-chen-hello-lambda \
--zip-file fileb://hello_lambda.zip