#!/bin/bash

set +x

echo 'dirname $0': $(dirname $0)
echo 'pwd': $(pwd)

cd $(dirname $0)

date >> ./a.txt
date >> ./b.txt
date >> ./a.txt
date >> ./b.txt
sleep 1
date >> ./a.txt
sleep 1
date >> ./b.txt
sleep 1
date >> ./a.txt
echo '[a.txt]:'
cat -n a.txt
echo '[b.txt]:'
cat -n b.txt
echo '[diff a.txt b.txt]:'
diff a.txt b.txt
echo '[diff b.txt a.txt]:'
diff b.txt a.txt
echo '[diff -u b.txt a.txt]:'
diff -u b.txt a.txt
rm *.txt
