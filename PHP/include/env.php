<?php
declare( strict_types=1 );
session_start();

function printServerSettings() {
    var_dump( $_SERVER );
    // foreach ( $_SERVER as $key => $value ) {
    //     echo '$_SERVER[ '.$key.' ]: '.$value.PHP_EOL;
    // }
}

function buildDefaultSessionElem() {
    $_SESSION[ 'Jacky' ] = '43';
    $_SESSION[ 'Vivian' ] = '50';
}