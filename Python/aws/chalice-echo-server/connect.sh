#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

ENDPOINT=wss://olvtey3phb.execute-api.eu-central-1.amazonaws.com/api
# ENDPOINT=wss://127.0.0.1:8000

pipenv run wsdump $ENDPOINT/