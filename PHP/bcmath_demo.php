<?php
declare( strict_types=1 );


$a = 1.24;
$a2 = 1.24000001;
$b = 5.678;
$c = -0.26;


echo 'Default bcscale='.bcscale().PHP_EOL;
bcscale( 2 );
echo 'After bcscale(2)='.bcscale().PHP_EOL;
echo "bcadd( $a, $b, 0 )=".bcadd( strval($a), strval($b), 0 ).PHP_EOL;
echo "bcadd( $a, $b, 1 )=".bcadd( strval($a), strval($b), 1 ).PHP_EOL;
echo "bcadd( $a, $b, 2 )=".bcadd( strval($a), strval($b), 2 ).PHP_EOL;
echo "bcadd( $a, $b, 3 )=".bcadd( strval($a), strval($b), 3 ).PHP_EOL;
echo "bcadd( $a, $b, 4 )=".bcadd( strval($a), strval($b), 4 ).PHP_EOL.PHP_EOL;

echo "bcsub( $a, $b, 4 )=".bcsub( strval($a), strval($b), 4 ).PHP_EOL;
echo "bcsub( $a, $c, 4 )=".bcsub( strval($a), strval($c), 4 ).PHP_EOL.PHP_EOL;

echo "bccomp( $b, $a )=".bccomp( strval($b), strval($a) ).PHP_EOL;
echo "bccomp( $a, $a2, 7 )=".bccomp( strval($a), strval($a2), 7 ).PHP_EOL;
echo "bccomp( $a, $a2, 8 )=".bccomp( strval($a), strval($a2), 8 ).PHP_EOL.PHP_EOL;

echo "bcdiv( $b, $a, 4 )=".bcdiv( strval($b), strval($a), 4 ).PHP_EOL;
echo "bcmod( $b, $a, 4 )=".bcmod( strval($b), strval($a), 4 ).PHP_EOL;
echo "bcmul( $b, $a, 4 )=".bcmul( strval($b), strval($a), 4 ).PHP_EOL;
echo "bcpow( $a, 5, 0 )=".bcpow( strval($a), '5', 0 ).PHP_EOL;
echo "bcsqrt( $a, 4 )=".bcsqrt( strval($a), 4 ).PHP_EOL;