#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306
USERID=100123456

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE lucky-mch-0; \
DESCRIBE account;
SELECT id, mch_id, username, created_at, updated_at \
FROM account \
WHERE id='$USERID';
'

# mysql -u root -p123456 -h $HOST -P $PORT -e \
# '
# USE lucky-mch-0; \
# INSERT INTO account (id, mch_id, brand_code, username, anonymous_aid, avatar, gender, status, is_virtual, password_hash) \
# VALUES (100123456, 100, "cr", "123456", "28900000006", 0, 1, 0, 0, "pbkdf2:$p5k2$$51aa0a5881ce054f$Nbiw1.aFUkQK8TCd6fQ7qy29nS787hr4");
# '

mysql -u root -p123456 -h $HOST -P $PORT -e \
'
USE lucky-mch-0; \
INSERT INTO account_asset (user_id, mch_id, credit, safe_amount) \
VALUES (100123456, 100, 1000000, 0);
'

