#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE lucky-mch-0; \
SELECT id, username, updated_at, NOW() as now, ROW_COUNT() as rc \
FROM account \
ORDER BY id DESC \
LIMIT 30 \
;
'