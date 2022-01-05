#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306
USERID=1006
DATABASE=lucky-mch-0

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE '$DATABASE'; \
SELECT account_asset.user_id, account.mch_id, account.username, account_asset.credit, \
    account.created_at AS acc_created_at, \
    account.updated_at AS acc_updated_at, \
    account_asset.created_at AS asset_created_at, \
    account_asset.updated_at AS asset_updated_at \
FROM account \
INNER JOIN account_asset ON account_asset.user_id=account.id \
WHERE account_asset.user_id='$USERID';
'