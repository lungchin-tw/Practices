#!/bin/bash

set -x

echo 'dirname $0': $(dirname $0)
echo 'pwd': $(pwd)

cd $(dirname $0)

du -d 1 /var/log/ | sort -rh
sleep 3

du -csh /var/log/* | sort -rh
