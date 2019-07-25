#!/bin/bash

set -x

echo $(dirname $0)
echo $(pwd)

cd $(dirname $0)

ROOT_FOLDER=$(pwd)
BASE=$(basename $(pwd))