#!/bin/bash

set +x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)

echo '[pushd $(dirname $0)]:'
pushd $(dirname $0)
echo '[pwd]:' $(pwd)

echo '[popd]:'
popd
echo '[pwd]:' $(pwd)
