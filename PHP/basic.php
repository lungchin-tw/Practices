<?php

echo 'echo Hello, World'.PHP_EOL;
eCHo 'eCHo <h2>PHP is Fun!</h2>'.PHP_EOL;
ECHO 'ECHO This ', 'string ', 'was ', 'made ', 'with multiple parameters.'.PHP_EOL;

$color = 'red';
echo '$color: '.$color.PHP_EOL;
// echo "coLor = $coLor;\n"; <= This result will be [ Notice: Undefined variable ... ]

// global keyworld
$gx = 5;
$gy = 10;

function makeGlobalVariable() {
    $GLOBALS['gy'] = $GLOBALS['gx'] + $GLOBALS['gy'];
    /* same result.
    global $gx, $gy; // for accessing global scope variables
    $gy = $gx + $gy;
    */
}

function experimentStaticVariable() {
    static $static_x = 0;
    echo '$static_x++: '.$static_x++.PHP_EOL;
}

echo '==================== Make Global Variable =================='.PHP_EOL;
makeGlobalVariable();
echo 'gy = $gy'.PHP_EOL;
echo '============================================================'.PHP_EOL.PHP_EOL;

echo '==================== Experiment Static Variable ============'.PHP_EOL;
experimentStaticVariable();
experimentStaticVariable();
experimentStaticVariable();
echo '============================================================'.PHP_EOL.PHP_EOL;

echo '==================== Data Types ============'.PHP_EOL;
$var_int = 65535;
echo 'var_dump($var_int)'.PHP_EOL; 
var_dump( $var_int );

echo PHP_EOL;
$var_double = 1.234;
echo 'var_dump($var_double)'.PHP_EOL;
var_dump( $var_double );

echo PHP_EOL;
$var_boolean = true;
echo 'var_dump($var_boolean)'.PHP_EOL;
var_dump( $var_boolean );

echo PHP_EOL;
$var_array = array( 'Abel', 'Aiden', 'Jacky', 'JJ' );
echo 'var_dump($var_array)'.PHP_EOL;
var_dump( $var_array );

echo PHP_EOL;
class Car {
    public $modelName = '';

    function __construct( $model_name ) {
        echo 'Class: '.__CLASS__.', Function: '.__FUNCTION__.', Method: '.__METHOD__.PHP_EOL;
        echo 'Dir: '.__DIR__.', File: '. __FILE__.', Line: '.__LINE__.PHP_EOL;
        echo 'Namespace: '.__NAMESPACE__.', Trait: '.__TRAIT__.PHP_EOL;
        echo 'Param $modelName: '.$model_name.', PHP_EOL: '.PHP_EOL;
        $this->modelName = $model_name;
    }
}

$new_car1 = new Car( 'BMW 3 Series' );
var_dump( $new_car1 );
$new_car2 = new Car( 'Benz C Class' );
var_dump( $new_car2 );
echo '============================================================'.PHP_EOL.PHP_EOL;

// Experiment NULL
{
    $var_string_uninit;
    echo '($var_string_uninit == NULL): '.( $var_string_uninit == NULL ).PHP_EOL;
    echo 'var_dump($var_string_uninit)'.PHP_EOL;
    var_dump( $var_string_uninit );

    $var_null = NULL;
    echo 'var_dump($var_null)'.PHP_EOL;
    var_dump( $var_null );
}

?>