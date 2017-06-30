#!/bin/sh

CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

rm -rf $CUR_FOLDER/build
mkdir $CUR_FOLDER/build
mkdir $CUR_FOLDER/build/Debug
mkdir $CUR_FOLDER/build/Release