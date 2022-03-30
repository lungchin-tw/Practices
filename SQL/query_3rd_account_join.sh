#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306
USERID=1006
DATABASE=lucky-mch-0

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE '$DATABASE'; \
SELECT \
    account.mch_id AS acc_mch_id, \
    account.id AS acc_id, \
    account.username AS acc_username, \
    batch_tcg_user.id AS tcg_user_id, \
    batch_tcg_user.user_id AS tcg_user_id \
FROM account INNER JOIN batch_tcg_user ON batch_tcg_user.user_id=account.id
LIMIT 10;
'