<?php 
declare( strict_types=1 );

$a = array
(
    array( 'x' => 1, 'y' => 2 )
);

$b = $a;
$b[ 0 ]['x'] = 10;

print_r( $a );
print_r( $b );