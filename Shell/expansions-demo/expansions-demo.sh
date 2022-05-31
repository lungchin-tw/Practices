#!/bin/bash

set +x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)

echo '[pushd $(dirname $0)]:'
pushd $(dirname $0)
echo '[pwd]:' $(pwd)

sleep 3

echo '[~]:' ~
echo '[$PATH]:' $PATH
echo '[$USER]:' $USER

sleep 3

echo '[{a..d}.w]: ' {a..d}.w
touch {a..d}.w
echo '[{a,c}.{x,xy,xyz}]:' {a,c}.{x,xy,xyz}
touch {a,c}.{x,xy,xyz}
echo '[*]:' *
echo '[*.?]:' *.?
echo '[*.??]:' *.??
echo '[*.???]:' *.???
sleep 3
rm -v {a..d}.w {a,c}.{x,xy,xyz}

sleep 3

echo '[popd]:'
popd
echo '[pwd]:' $(pwd)
