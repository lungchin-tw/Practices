<?php 
declare( strict_types=1 );

require_once 'include/extended_class.php';


function DemoPrintBackTrace() {
    debug_print_backtrace();
}




echo PHP_EOL;
echo "Type 1: Simple callback".PHP_EOL;
echo "call_user_func( 'DemoPrintBackTrace' ): ".PHP_EOL;
call_user_func( 'DemoPrintBackTrace' );
echo PHP_EOL;


echo "Type 2: Call Static Class Method".PHP_EOL;
echo "call_user_func( array( 'BaseClass', 'printSymbol' ) ): ".PHP_EOL;
call_user_func( array( 'BaseClass', 'printSymbol' ) );
echo PHP_EOL;

$ext_inst = new \jacky\ExtendedClass();
echo PHP_EOL;

echo "Type 3: Call Object Method".PHP_EOL;
echo '$val = '.'call_user_func( array( '.'$ext_inst'.", 'getNum' ) ): ".PHP_EOL;
$val = call_user_func( array( $ext_inst, 'getNum' ) );
var_dump( $val );

echo PHP_EOL;