<?php 
declare( strict_types=1 );


$demo_obj = new stdClass();
$demo_obj->float_val = 1.234;
$demo_obj->string_val = 'Hello';

echo 'Demo var_dump():'.PHP_EOL;
var_dump( $demo_obj );
echo PHP_EOL;

echo 'Demo print_r():'.PHP_EOL;
print_r( $demo_obj );
echo PHP_EOL;

echo 'Demo get_defined_vars():'.PHP_EOL;
print_r( get_defined_vars() );
echo PHP_EOL;

function DemoPrintBackTrace() {
    debug_print_backtrace();
}

echo 'Demo debug_print_backtrace():'.PHP_EOL;
DemoPrintBackTrace();
echo PHP_EOL;

echo 'Demo debug_zval_dump( $demo_obj ):'.PHP_EOL;
debug_zval_dump( $demo_obj );
echo PHP_EOL;

$demo_obj_ref2 = $demo_obj;
echo 'Demo debug_zval_dump( $demo_obj_ref2 ):'.PHP_EOL;
debug_zval_dump( $demo_obj_ref2 );
echo PHP_EOL;


$demo_obj_ref3 = $demo_obj_ref2;
echo 'Demo debug_zval_dump( $demo_obj_ref3 ):'.PHP_EOL;
debug_zval_dump( $demo_obj_ref3 );
echo PHP_EOL;
