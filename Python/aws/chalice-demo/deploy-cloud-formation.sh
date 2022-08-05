#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

PKG_NAME=jacky-chen-cloud-formation-demo

pipenv run chalice package --profile jacky --merge-template resources.json $PKG_NAME

aws s3 mb s3://$PKG_NAME

aws cloudformation package \
--template-file ./$PKG_NAME/sam.json \
--s3-bucket $PKG_NAME \
--output-template-file ./$PKG_NAME.yaml

aws cloudformation deploy \
--template-file ./$PKG_NAME.yaml \
--stack-name $PKG_NAME \
--capabilities CAPABILITY_IAM
