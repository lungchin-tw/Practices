<?php 
declare( strict_types=1 );

$x = 0.1;
$y = 0.2;
$z = 0.2;
$w = 0.3;
$zero = 0;

echo '( $y == $z ): '.(( $y == $z ) ? 'true' : 'false');
echo PHP_EOL;

echo '( ( $y - $z ) == $zero ): '.(( ( $y - $z ) == $zero ) ? 'true' : 'false');
echo PHP_EOL;

$result = ( $x + $y );
var_dump( $result );
echo '( $result == $w ): '.(( $result == $w ) ? 'true' : 'false');
echo PHP_EOL;

echo sprintf( '$x: '."%0.20f", $x );
echo PHP_EOL;

echo sprintf( '$y: '."%0.20f", $y );
echo PHP_EOL;

echo sprintf( '$z: '."%0.20f", $z );
echo PHP_EOL;

echo sprintf( '$w: '."%0.20f", $w );
echo PHP_EOL;

echo sprintf( '$result: '."%0.20f", $result );
echo PHP_EOL;


$result = bcadd( strval($x), strval($y), 2 );
var_dump($result);
echo '( $result == $w ): '.(( $result == $w ) ? 'true' : 'false');
echo PHP_EOL;
echo sprintf( '$result: '."%0.20f", $result );
echo PHP_EOL;

$result = ( $y - $x );
var_dump($result);
echo '( $result == $x ): '.( ( $result == $x ) ? 'true' : 'false' );
echo PHP_EOL;


echo sprintf( '$result: '."%0.20f", $result );
echo PHP_EOL;