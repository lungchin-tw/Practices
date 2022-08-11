#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run chalice package --merge-template resources.json out
pipenv run aws cloudformation package --template-file out/sam.json \
--s3-bucket jacky-chen-demo --output-template-file out/template.yml