<?php
declare( strict_types=1 );

function printServerSettings() {
    var_dump( $_SERVER );
    // foreach ( $_SERVER as $key => $value ) {
    //     echo '$_SERVER[ '.$key.' ]: '.$value.PHP_EOL;
    // }
}