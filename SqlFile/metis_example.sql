
SELECT * FROM platform.users WHERE subsidiary_user_id='1060920' LIMIT 10
get id=112459

SELECT * FROM platform.log_bet WHERE user_id=112459 ORDER BY created_at DESC LIMIT 50
action=exchange: 玩家將籌碼帶入遊戲，bet_amount 是指帶入的籌碼數量
action=recompensate: 玩家離開遊戲時，剩下的籌碼，bet_result 是指剩下的籌碼數量
action=round: bet_amount = 下注金額，bet_result= 返還金額，所以剩下的金額會寫在 notes 的 new_money 的欄位

SELECT * FROM platform.log_cash_info WHERE user_id=112459 ORDER BY updated_at DESC LIMIT 50
log_cash_info 中的數值是乘上 10,000 倍之後的結果

-- 允許曼谷團隊的 IP
SELECT * FROM platform.manage_ip_info WHERE info = 'BangkokDev';

UPDATE platform.manage_ip_info 
SET startip = '$ip_decimal', endip = '$ip_decimal' 
WHERE info = 'BangkokDev';