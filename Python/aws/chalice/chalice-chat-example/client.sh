#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run wsdump wss://15nr1p3d0m.execute-api.eu-central-1.amazonaws.com/api/