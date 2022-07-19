#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run aws cloudformation deploy --template-file out/template.yml \
--stack-name JackyChenDemo --capabilities CAPABILITY_IAM