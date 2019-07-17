<?php 
declare( strict_types=1 );

$x = 0.1;
$y = 0.2;
$z = 0.2;
$zero = 0;

echo ( $y == $z ) ? 'true' : 'false';
echo PHP_EOL;

echo ( ( $y - $z ) == $zero ) ? 'true' : 'false';
echo PHP_EOL;

$result = ( $x + $y );
echo ( $result == 0.3 ) ? 'true' : 'false';
echo PHP_EOL;

var_dump( $result );

echo sprintf( "%0.20f", $x );
echo PHP_EOL;

echo sprintf( "%0.20f", $y );
echo PHP_EOL;

echo sprintf( "%0.20f", $z );
echo PHP_EOL;

echo sprintf( "%0.20f", $zero );
echo PHP_EOL;

echo sprintf( "%0.20f", $result );
echo PHP_EOL;

echo sprintf( "%0.20f", 0.3 );
echo PHP_EOL;

$result = bcadd( strval($x), strval($y), 2 );
echo ( $result == 0.3 ) ? 'true' : 'false';
echo PHP_EOL;