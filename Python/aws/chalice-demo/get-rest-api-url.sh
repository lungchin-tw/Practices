#! /usr/bin/bash

set -x


PROFILE=$1
API_NAME=$2

API_ID=$(aws --profile $PROFILE apigateway get-rest-apis --query "items[?name=='$API_NAME'] | [0].id")
API_ID=$(echo $API_ID | tr -d '"')
REGION=$(aws configure get $PROFILE.region)
echo https://$API_ID.execute-api.$REGION.amazonaws.com/api
