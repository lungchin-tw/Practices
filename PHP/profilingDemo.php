<?php 
declare( strict_types=1 );


function IAmCaller() {
    $start = microtime( true );
    $sum = 0;
    for ( $index = 0; $index < 10000000; ++$index )
    {
        $sum += $index;
    }
    $end = microtime( true );
    echo "Sum: $sum, Elapsed: ".($end - $start).PHP_EOL;

    sleep( 5 );
}

IAmCaller();
