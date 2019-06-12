<?php 
declare( strict_types=1 );

echo 'The Begining'.PHP_EOL;
echo PHP_EOL;

assert( false, new AssertionError( 'Test assert() with AssertionError' ) );
assert( false, new Exception( 'Test assert() with Exception' ) );

echo PHP_EOL;
echo 'The End';