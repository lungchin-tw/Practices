<?php 
declare( strict_types=1 );


$x = 0.123;
$y = 0.223;
$w = 0.3;


echo "Arithmetic 1:".PHP_EOL;
$result = ( $y - $x );
var_dump($result);
echo '( $result == $x ): '.( ( $result == $x ) ? 'true' : 'false' );
echo PHP_EOL;
echo PHP_EOL;


echo "Arithmetic 2:".PHP_EOL;
$result = ( $y + $x );
// $result = bcadd( strval($x), strval($y), 2 );
var_dump($result);
echo '( $result == $w ): '.( ( $result == $w ) ? 'true' : 'false' );
echo PHP_EOL;
echo PHP_EOL;

echo sprintf( '$x: '."%0.10f", $x );
echo PHP_EOL;
echo sprintf( '$y: '."%0.10f", $y );
echo PHP_EOL;
echo sprintf( '$w: '."%0.10f", $w );
echo PHP_EOL;
echo sprintf( '$result: '."%0.2f", $result );
echo PHP_EOL;
