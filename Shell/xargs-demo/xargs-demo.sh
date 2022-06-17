#!/bin/bash

set +x

pushd $(dirname $0)..
echo '[pwd]:' $(pwd)

ls | xargs stat

popd
echo '[pwd]:' $(pwd) 
