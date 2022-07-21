#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run aws sns publish \
--topic-arn arn:aws:sns:eu-central-1:422686820116:Jacky-Chen-Demo \
--subject "$1" \
--message "$2"