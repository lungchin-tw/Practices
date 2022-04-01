#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306
USERID=100123456
TABLE=account_asset

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE lucky-mch-0;

UPDATE '$TABLE'
SET updated_at="2022-03-29 18:03:02"
WHERE user_id='$USERID';

SELECT user_id, mch_id, credit, created_at, updated_at
FROM '$TABLE'
WHERE user_id='$USERID';
'