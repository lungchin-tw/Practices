#!/bin/bash

set +x

HOST=127.0.0.1
PORT=6379
DBNO=2
KEY=bg:user:token
USERID=1002020307
# USERID=1005201314


TOKEN='{"token": "6ce3a74ba23d4facb6b250a995e8a7d2", "ip": "13.250.3.58", "addr": "Singapore", "created_at": 1591244907}'
eval "redis-cli -h $HOST -p $PORT -n $DBNO hset $KEY $USERID '$TOKEN'"

CMD="redis-cli -h $HOST -p $PORT -n $DBNO hget $KEY $USERID"
VAL=$(eval $CMD)
echo $VAL

