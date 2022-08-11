#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

PKG_NAME=jacky-chen-chalice-cd-demo

aws cloudformation deploy \
--profile jacky \
--stack-name $PKG_NAME \
--template-file ./pipeline.json \
--capabilities CAPABILITY_IAM