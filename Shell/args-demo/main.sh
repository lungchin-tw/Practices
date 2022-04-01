#!/bin/bash

set -x


# Try ./main.sh x y z

#!/bin/bash

set +x

echo 'dirname $0': $(dirname $0)
echo 'pwd': $(pwd)

pushd $(dirname $0)

echo '$0:' $0
echo '$1:' $1
echo '$2:' $2
echo '$#:' $#
echo '$@:' $@
echo '"$@":' "$@"
echo '$*:' $*
echo '"$*":' "$*"

for arg in "$@"; do
    echo 'for "$@":' $arg
done

for arg in "$*"; do
    echo 'for "$*":' $arg
done


./show_args.sh ${@:2}
popd