#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

PKG_NAME=jacky-chen-cloud-formation-demo

aws cloudformation delete-stack \
--stack-name $PKG_NAME

aws s3 rb s3://$PKG_NAME --force