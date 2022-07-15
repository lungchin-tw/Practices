#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

# METHOD 1:
# which awscurl

awscurl -v --region eu-central-1 --service lambda https://g6oypxkzesa5z5m7bznvgmbjti0krksb.lambda-url.eu-central-1.on.aws/

# METHOD 2:
# aws lambda invoke --function-name jacky-chen-url-function-exercise out

# aws lambda invoke --function-name jacky-chen-url-function-exercise --cli-binary-format raw-in-base64-out --payload '{"key": "value"}' out
# sed -i'' -e 's/"//g' out
# sleep 15
# aws logs get-log-events --log-group-name /aws/lambda/jacky-chen-url-function-exercise --log-stream-name $(cat out) --limit 5