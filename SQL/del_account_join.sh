#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306
DATABASE=lucky-mch-0
ROBOTID=35
TEMPTABLE=temp
NUM=355000

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE '$DATABASE';
SELECT COUNT(*) FROM account_asset
INNER JOIN account
ON account_asset.user_id=account.id
WHERE account.is_virtual='$ROBOTID';
'

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE '$DATABASE';
CREATE TEMPORARY TABLE '$TEMPTABLE' AS (
SELECT account.id
FROM account INNER JOIN account_asset
ON account.id=account_asset.user_id
WHERE account.is_virtual='$ROBOTID'
LIMIT '$NUM');
SELECT COUNT(*) FROM '$TEMPTABLE';
SELECT * FROM '$TEMPTABLE';

DELETE account_asset
FROM '$TEMPTABLE' INNER JOIN account_asset ON '$TEMPTABLE'.id=account_asset.user_id;

DELETE account
FROM '$TEMPTABLE' INNER JOIN account ON '$TEMPTABLE'.id=account.id;
'

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE '$DATABASE';

SELECT COUNT(*) FROM account WHERE account.is_virtual='$ROBOTID';

SELECT COUNT(*) FROM account_asset
INNER JOIN account
ON account_asset.user_id=account.id
WHERE account.is_virtual='$ROBOTID';
'