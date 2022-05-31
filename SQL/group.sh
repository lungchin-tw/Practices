#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE lucky-mch-0; \
SELECT avatar, COUNT(avatar) AS AvatarCounter \
, row_number() AS RowNumber
FROM account \
GROUP BY avatar;
'

