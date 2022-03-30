#!/bin/bash

set -x

HOST=127.0.0.1
PORT=3306
DATABASE=lucky-mch-0
LOGINID=1002020307
USERID=1005201314
CONNECT="mysql -u root -p123456 -h $HOST -P $PORT -e"

eval "$CONNECT 'USE '$DATABASE'; DESCRIBE batch_bg_user;'"
eval "$CONNECT 'USE '$DATABASE'; 
DESCRIBE batch_bg_trans_record;
'"

eval "$CONNECT 'USE '$DATABASE'; 
SELECT id, user_id, bg_user_id, mch_id, order_id, game_id, play_id, issue_id, amount, calc_amount, recalc_amount FROM batch_bg_trans_record
WHERE bg_user_id='$LOGINID' AND order_id=6856898270041948198;
'"

eval "$CONNECT 'USE '$DATABASE'; 
DELETE FROM batch_bg_trans_record
WHERE bg_user_id='$LOGINID' AND (order_id=100 OR order_id=101);
'"
