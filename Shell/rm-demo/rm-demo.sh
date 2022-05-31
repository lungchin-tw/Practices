#!/bin/bash

set -x

echo 'dirname $0': $(dirname $0)
echo 'pwd': $(pwd)

cd $(dirname $0)

# build test env
touch cat.test dog.test carrot.test

# sleep for 3 seconds
sleep 3 

# -v: verbose
rm -v *.test