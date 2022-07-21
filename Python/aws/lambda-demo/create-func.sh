#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

TRACK=track.json
echo "" >> $TRACK

aws --profile jacky lambda create-function \
--function-name jacky-chen-hello-lambda \
--zip-file fileb://hello_lambda.zip \
--handler lambda.handler \
--runtime python3.9 \
--architectures arm64 \
--role arn:aws:iam::422686820116:role/jacky-chen-hello-lambda \
| tee -a $TRACK