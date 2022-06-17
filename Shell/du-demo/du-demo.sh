#!/bin/bash

set +x

pushd $(dirname $0)
echo '[pwd]:' $(pwd)

echo "[du ..]:"
du -h .. | sort -hr
sleep 3

popd
echo '[pwd]:' $(pwd) 
