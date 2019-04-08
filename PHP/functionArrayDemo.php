<?php
declare( strict_types=1 );

function getRandNumber() : int {
    return rand();
}

function getConstValue() : int {
    return 10;
}

$callback_list = array(
    '0' => 'getRandNumber',
    1 => 'getConstValue'
);

echo 'call_user_func( $callback_list[ 1 ] ): '.call_user_func( $callback_list[ 1 ] ).PHP_EOL;