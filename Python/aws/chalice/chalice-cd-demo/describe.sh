#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

PKG_NAME=jacky-chen-chalice-cd-demo

aws --profile jacky cloudformation describe-stacks \
--stack-name $PKG_NAME \
--query "Stacks[0].Outputs[?OutputKey=='SourceRepoURL'] | [0].OutputValue"