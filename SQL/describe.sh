#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306
TABLE_NAME=batch_imesb_trans_record

# mysql -v --user=root --password=123456 --host=$HOST --port=$PORT --execute='SHOW DATABASES;'
mysql -v -u root -p123456 -h $HOST -P $PORT -e 'SHOW DATABASES;'
mysql -v -u root -p123456 -h $HOST -P $PORT -e \
'
USE lucky-mch-0; \
SHOW TABLES;
DESCRIBE '$TABLE_NAME';
# EXPLAIN '$TABLE_NAME';

SELECT * FROM '$TABLE_NAME' 
WHERE bet_no=2
LIMIT 5;
'

