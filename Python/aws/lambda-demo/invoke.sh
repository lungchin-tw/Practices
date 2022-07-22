#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

ENDPOINT=https://4r1ucm8pi3.execute-api.eu-central-1.amazonaws.com/jacky-chen-hello-lambda
         
# METHOD 1:
# which awscurl

# awscurl -v --profile jacky --service execute-api -X POST -d '{"action": "greetings"}' \
# https://gge57faqd3.execute-api.eu-central-1.amazonaws.com/default/jacky-chen-hello-lambda/


# METHOD 2:
# aws --debug --profile jacky lambda invoke --function-name jacky-chen-hello-lambda \
# --payload '{"action": "greeting"}' \
# response.json

# aws --profile jacky lambda invoke --function-name jacky-chen-hello-lambda \
# --payload '{"action": "greeting"}' \
# response.json \
# --log-type Tail \
# --query 'LogResult' --output text | base64 -d


# METHOD: 3, use API Gateway
echo '{"action":"greeting"}' | pipenv run http --debug \
POST $ENDPOINT

# curl -v -X POST -H 'content-type: application/json' \
# --data '{"action":"greeting"}' $ENDPOINT