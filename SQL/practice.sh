#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306
DB_NAME=lucky-mch-0
TABLE_NAME=batch_dg_trans_record
SERIAL=3ccfd324cae9470089a59bd54c84e5f

mysql -v -u root -p123456 -h $HOST -P $PORT -e \
'
USE '$DB_NAME';
SELECT id, user_id, dg_user_id, mch_id, serial_no, ticket_id, status, amount
FROM '$TABLE_NAME'
WHERE serial_no='\"$SERIAL\"';

DELETE FROM '$TABLE_NAME'
WHERE serial_no='\"$SERIAL\"';
'

