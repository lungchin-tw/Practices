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


{
    echo '========================= TRIM ====================='.PHP_EOL;
    $origin_str = ' ab cde ';
    echo 'strlen: '.strlen($origin_str).PHP_EOL;

    $rtrim_str = rtrim( $origin_str );
    echo 'rtrim: '.$rtrim_str.', strlen: '.strlen($rtrim_str).PHP_EOL;

    $ltrim_str = ltrim( $origin_str );
    echo 'ltrim: '.$ltrim_str.', strlen: '.strlen($ltrim_str).PHP_EOL;

    $trim_str = trim( $origin_str );
    echo 'trim: '.$trim_str.', strlen: '.strlen($trim_str).PHP_EOL;
    
    echo PHP_EOL;
}

{
    echo '========================= SUBSTR ====================='.PHP_EOL;

    $origin_str = 'Hello, World!';
    $sub_str = substr($origin_str, -1);
    echo "substr($origin_str, -1): ".$sub_str.PHP_EOL;
    
    echo ( ( $sub_str !== '/' ) ? 'true' : 'false' ).PHP_EOL;

    $origin_str = $origin_str.'/';
    echo $origin_str;

    echo PHP_EOL;
}
