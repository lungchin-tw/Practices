#!/bin/bash

set -x

echo 'dirname $0': $(dirname $0)
echo 'pwd': $(pwd)

cd $(dirname $0)

date >> ./test-uniq.txt
date >> ./test-uniq.txt
date >> ./test-uniq.txt
date >> ./test-uniq.txt
sleep 1
date >> ./test-uniq.txt
date >> ./test-uniq.txt
cat test-uniq.txt
sleep 1
uniq -c test-uniq.txt | sort -n
rm test-uniq.txt
