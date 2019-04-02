<?php
declare( strict_types=1 );


$demoArray = array( 1, 5, 3, 9 );

function calcSum( int ...$values ) : int {
    echo __FUNCTION__.', count($values): '.count($values).PHP_EOL;
    
    $result = 0;
    foreach ( $values as $elem ) {
        $result += $elem;
    }

    return $result;
}

var_dump( $demoArray );

echo 'Sum: '.calcSum( ...$demoArray ).PHP_EOL;
echo 'Sum of calcSum(): '.calcSum().PHP_EOL;