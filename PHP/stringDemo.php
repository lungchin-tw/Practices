<?php 
declare( strict_types=1 );

$str = '/html/index.php/game/editor_login';
$search = 'index.php';

$pos = strpos( $str, $search );
var_dump( $pos );

if ( $pos != false ) {
    $left = substr( $str, ( $pos + strlen($search) + 1 ) );
    var_dump( $left );
}

