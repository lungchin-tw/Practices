#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run chalice logs -n websocket_connect
pipenv run chalice logs -n websocket_message
pipenv run chalice logs -n websocket_disconnect