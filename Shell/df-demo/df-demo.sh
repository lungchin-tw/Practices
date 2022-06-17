#!/bin/bash

set +x

pushd $(dirname $0)
echo '[pwd]:' $(pwd)

echo "[df -h]:"
df -h
sleep 3

popd
echo '[pwd]:' $(pwd) 
