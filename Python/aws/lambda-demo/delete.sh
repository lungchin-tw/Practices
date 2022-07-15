#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

which aws
aws lambda delete-function --function-name jacky-chen-url-function-exercise