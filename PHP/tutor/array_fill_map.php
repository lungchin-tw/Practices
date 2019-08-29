<?php
declare( strict_types=1 );

{
    $result = array_fill( 0, 10, 0 );
    // print_r( $result );
}


$ax = array( 0, 1, 2, 3 );
$ay = array( 2, 3, 4, 5 );

{
    $result = array_map( 
        function ( int $x ): int {
            return $x * $x;
        },
        $ay
    );
    // print_r( $result );
}

{
    $result = array_map( 
        function ( int $x, int $y ): int {
            return $x * $y;
        },
        $ay, $ax
    );
    print_r( $result );
}

// Question: Which design pattern is applied by API array_map?