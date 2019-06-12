<?php
/*
* Experiment Advanced Skill
*/

declare( strict_types=1 );

// Experiment require
require 'include/env.php';


define( 'DEFAULT_SESSION', false );

printServerSettings();

if ( DEFAULT_SESSION ) {
    buildDefaultSessionElem();
}

var_dump( $_SESSION );

/**
 * Expirement Exceptions
 */
{
    define( 'FLOAT_NEAR_ZERO', 0.000000001 );
    echo '==================== Expirement Exceptions =================='.PHP_EOL;
    function inverse( float $value ) : float {
        if ( isset( $value ) == false ) {
            var_dump( debug_backtrace() );
            throw new Exception( 'isset( $value ) == false.' );
        } elseif ( abs($value) < FLOAT_NEAR_ZERO ) {
            var_dump( debug_backtrace() );
            throw new Exception( '( abs($value) < FLOAT_NEAR_ZERO ).' );
        }

        return 1/$value;
    }

    try {
        echo 'inverse( 3 ): '.inverse( 3 ).PHP_EOL;
    } catch ( Exception $e ) {
        echo $e->__toString().PHP_EOL;
    } finally {
        echo 'First finally'.PHP_EOL;
    }

    try {
        echo 'inverse( 0 ): '.inverse( 0 ).PHP_EOL;
    } catch ( Exception $e ) {
        echo $e->__toString().PHP_EOL;
        echo 'Exception::Message='.$e->getMessage().PHP_EOL;
    } finally {
        echo 'Second finally'.PHP_EOL;
    }
    echo '============================================================'.PHP_EOL.PHP_EOL;
}

/**
 * Expirement Classs, Interface
 */
{
    require_once 'include/interface.php';
    require_once 'include/base_class.php';
    require_once 'include/extended_class.php';

    echo '==================== Expirement Classs, Interface =================='.PHP_EOL;
    print_r( new stdClass() );
    print_r( new class{} );
    echo 'namspace of IInterface: '.IInterface::class.PHP_EOL;
    echo 'namspace of BaseClass: '.BaseClass::class.PHP_EOL;
    echo PHP_EOL.'BaseClass::printSymbol(): '.PHP_EOL;
    BaseClass::printSymbol();
    echo PHP_EOL;
    echo 'namspace of jacky\ExtendedClass: '.jacky\ExtendedClass::class.PHP_EOL;
    echo 'IInterface::CONST_INTERFACE_INT: '.IInterface::CONST_INTERFACE_INT.PHP_EOL;
    echo 'BaseClass::CONST_BASE_VALUE: '.BaseClass::CONST_BASE_VALUE.PHP_EOL;
    echo '(new BaseClass())->getNum(): '.(new BaseClass())->getNum().PHP_EOL;
    echo '(new jacky\ExtendedClass())->getNum(): '.(new jacky\ExtendedClass())->getNum().PHP_EOL;
    
    echo '===================================================================='.PHP_EOL.PHP_EOL;
}