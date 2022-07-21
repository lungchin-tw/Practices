#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run chalice delete
pipenv run aws sns delete-topic --topic-arn arn:aws:sns:eu-central-1:422686820116:Jacky-Chen-Demo