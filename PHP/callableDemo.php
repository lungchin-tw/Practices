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


echo "Type 2-1: Call Static Class Method".PHP_EOL;
echo "call_user_func( array( 'BaseClass', 'printSymbol' ) ): ".PHP_EOL;
call_user_func( array( 'BaseClass', 'printSymbol' ) );
echo PHP_EOL;

echo "Type 2-2: Call Static Class Method Version 2".PHP_EOL;
echo "call_user_func( 'BaseClass::printSymbol' ): ".PHP_EOL;
call_user_func( 'BaseClass::printSymbol' );
echo PHP_EOL;

echo "Type 2-3: Call Relative Static Class Method".PHP_EOL;
echo "call_user_func( array( '\jacky\ExtendedClass', 'parent::printSymbol' ) ): ".PHP_EOL;
call_user_func( array( '\jacky\ExtendedClass', 'parent::printSymbol' ) );

echo PHP_EOL;

$ext_inst = new \jacky\ExtendedClass();
echo PHP_EOL;

echo "Type 3: Call Object Method".PHP_EOL;
echo '$val = '.'call_user_func( array( '.'$ext_inst'.", 'getNum' ) ): ".PHP_EOL;
$val = call_user_func( array( $ext_inst, 'getNum' ) );
var_dump( $val );
echo PHP_EOL;


{
    class CustomizedCallee {
        public function __invoke( string $val ) : string {
            echo __METHOD__.', Pass in $val= '.$val.PHP_EOL;
            return $val;
        }
    }

    echo "Type 4: Objects Implementing __invoke can be used as callables.".PHP_EOL;
    echo '$val = '."call_user_func( (new CustomizedCallee()), 'This is a customized callee.' )".PHP_EOL;
    $val = call_user_func( (new CustomizedCallee()), 'This is a customized callee.' );
    var_dump( $val );
    echo PHP_EOL;
}
