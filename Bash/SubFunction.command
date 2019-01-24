#!/bin/sh

## CUR_FOLDER=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

set -x
echo "`dirname "$0"`"
cd "`dirname "$0"`"
echo "$@"
shift 2
echo "$@"