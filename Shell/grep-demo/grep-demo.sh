#!/bin/bash

set +x

pushd $(dirname $0)
echo '[pwd]:' $(pwd)

echo '[grep -n dirname ../dirname.sh]:'
grep -n dirname ../dirname.sh 
sleep 3

echo '[grep -nr pushd .. ]:'
grep -nr pushd ..
sleep 3

echo '[grep -nri PUSHD .. ]:'
grep -nri PUSHD ..
sleep 3

popd
echo '[pwd]:' $(pwd)
