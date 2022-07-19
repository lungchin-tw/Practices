#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run aws cloudformation describe-stacks --stack-name JackyChenDemo \
--query "Stacks[0].Outputs[?OutputKey=='WebsocketConnectEndpointURL'].OutputValue" \
--output text