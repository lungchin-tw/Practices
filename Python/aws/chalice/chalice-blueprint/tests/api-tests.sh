#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)..

# ENDPOINT=$(pipenv run chalice url --stage dev)
# ENDPOINT=$(./get-rest-api-url.sh jacky jacky-chen-chalice-blueprint)
ENDPOINT=http://127.0.0.1:8000

pipenv run http $ENDPOINT/
pipenv run http $ENDPOINT/bp/
