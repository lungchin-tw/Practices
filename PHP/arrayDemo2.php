<?php 
declare( strict_types=1 );


class data {
    public $x = 0; 
}

$array = array();

$array[ '199' ] = array();

$elem = new data();
$elem->x = 10;
array_push( $array[ '199' ], $elem );
array_push( $array[ '199' ], new stdClass() );
array_push( $array[ '199' ], new stdClass() );

echo 'is_array( $array ): '.is_array( $array ).PHP_EOL;
echo 'is_array( $array[ \'199\' ] ): '.is_array( $array[ '199' ] ).PHP_EOL;

function demo_func( array $value ) {
    var_dump( $value );
}

demo_func( $array );
demo_func( $array[ '199' ] );

$clone = $array[ '199' ];
$clone[ 0 ]->x = 20;

demo_func( $array[ '199' ] );
demo_func( $clone );

$elem->x = 100;
$array[ '199' ][ 87 ] = clone $elem;


echo '================= foreach =============='.PHP_EOL;
foreach ( $array as $key => $value ) {
    echo '1st Layer Key: ';
    print_r( $key );
    echo PHP_EOL;
    foreach ( $value as $key2 => $value2 ) {
        echo '2nd Layer Key: ';
        print_r( $key2 );
        echo PHP_EOL;
        echo '2nd Layer value: ';
        print_r( $value2 );
        echo PHP_EOL;
    }
}

echo '================= clone by array_map =============='.PHP_EOL;
$clone = array_map(
    function ( array $coll ): array {
        $replica = array();
        foreach ( $coll as $key => $value ) {
            $replica[ $key ] = $value;
        }

        return $replica;
    },
    $array
);

$clone[ '199' ][ 0 ] = 10000;

var_dump( $array );
var_dump( $clone );
