#!/bin/bash

set +x

pushd $(dirname $0)
echo '[pwd]:' $(pwd)

echo "[find .. -name '*demo*.sh']:"
find .. -name '*demo.sh'
sleep 3

echo "[find .. -type d]:"
find .. -type d
sleep 3

echo "[find .. -type f -iname '*DEMO*' -or -name '*.command']:"
find .. -type f -iname '*DEMO*' -or -name '*.command'
sleep 3

echo "[find .. -type f -iname -exec]:"
find .. -type f -iname '*.command' -exec ls -l {} \;
sleep 3

popd
echo '[pwd]:' $(pwd)
