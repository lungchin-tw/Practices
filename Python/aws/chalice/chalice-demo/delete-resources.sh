#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

export AWS_PROFILE=jacky
echo $AWS_PROFILE

aws s3 rb s3://jacky-chen-cloud-formation-demo --force

TOPIC=$(aws sns create-topic --name jacky-chen-sns-demo)
TOPIC_ARN=$(echo $TOPIC | jq -r '.TopicArn')
aws sns delete-topic --topic-arn $TOPIC_ARN
