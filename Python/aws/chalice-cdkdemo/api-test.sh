#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run http POST $ENDPOINT/users username=JackyChen
pipenv run http $ENDPOINT/users/JackyChen