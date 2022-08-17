#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

ENDPOINT=$(pipenv run chalice url --stage dev)
URL=${ENDPOINT}proxy/http

for i in {1..100}
do
    echo "Round $i:"
    pipenv run http $URL
done
