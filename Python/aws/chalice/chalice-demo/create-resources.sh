#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

export AWS_PROFILE=jacky

aws s3 mb s3://jacky-chen-cloud-formation-demo
aws sns create-topic --name jacky-chen-sns-demo

