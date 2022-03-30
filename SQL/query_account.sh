#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306
USERID=100123456

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE lucky-mch-0; \
SELECT id, mch_id, username, created_at, updated_at \
FROM account \
WHERE id='$USERID';
'

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE lucky-mch-0; \
SELECT user_id, mch_id, credit, created_at, updated_at \
FROM account_asset \
WHERE user_id='$USERID';
'

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE lucky-mch-0; \
SELECT user_id, mch_id, amount, title, type, balance, created_at, updated_at \
FROM asset_record \
WHERE user_id='$USERID' \
ORDER BY updated_at DESC
LIMIT 3;
'
