#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

ROLE_NAME=jacky-chen-hello-lambda
TRACK=track.json
echo "" >> $TRACK

aws --profile jacky iam create-role --role-name $ROLE_NAME \
--assume-role-policy-document file://trust-policy.json \
| tee -a $TRACK

aws --profile jacky iam attach-role-policy --role-name $ROLE_NAME \
--policy-arn arn:aws:iam::aws:policy/service-role/AWSLambdaBasicExecutionRole