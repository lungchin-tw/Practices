<?php
declare( strict_types=1 );


{
    echo '==================== Associative Array : Demo isset =================='.PHP_EOL;
    $demoArray = array();

    for ( $count = 0; $count < 10; ++$count ) {
        $rand_value = rand( 1, 100 );

        echo 'isset( $demoArray[ '.$rand_value.' ] ): '.(int)isset( $demoArray[ $rand_value ] ).PHP_EOL;
        
        if ( ( isset( $demoArray[ $rand_value ] ) ) == false ) {
            $demoArray[ $rand_value ] = 1;
        } else {
            $demoArray[ $rand_value ] += 1;
        }
    }

    var_dump( $demoArray );
    echo '======================================================================'.PHP_EOL.PHP_EOL;
}

{
    echo '============================ Array : Demo sort ======================='.PHP_EOL;

    class sortElem {
        private $_key = 0;
        private $_value = 0;

        public function getKey() : int { 
            return $this->_key;
        }

        public function getValue() : int { 
            return $this->_value;
        }


        public function __construct( int $key, int $value ) {
            $this->_key = $key;
            $this->_value = $value;
        }
    }

    $sortArrayDemo = array();

    for ( $count = 0; $count < 5; ++$count ) {
        array_push( $sortArrayDemo, new sortElem( rand( 1, 100 ), rand( 1, 100 ) ) );
    }

    echo 'Before Sorting:'.PHP_EOL;
    var_dump( $sortArrayDemo );
    echo 'End Sorting:'.PHP_EOL;
    usort( 
        $sortArrayDemo,
        function ( sortElem $a, sortElem $b ) : int {
            return ( $a->getValue() <=> $b->getValue() );
        } 
    );
    var_dump( $sortArrayDemo );
    echo '======================================================================'.PHP_EOL.PHP_EOL;
}

{
    echo '============================ Array : Splice Demo ======================='.PHP_EOL;

    $spliceArrayDemo = array();

    for ( $count = 0; $count < 5; ++$count ) {
        array_push( $spliceArrayDemo, rand( 1, 100 ) );
    }

    echo 'Before Splice:'.PHP_EOL;
    var_dump( $spliceArrayDemo );
    echo 'After Splice: array_splice( $spliceArrayDemo, 0, 10 )'.PHP_EOL;
    $removedArray = array_splice( $spliceArrayDemo, 0, 10 );

    echo 'Removed Array:'.PHP_EOL;
    var_dump( $removedArray );

    echo 'Remained Array:'.PHP_EOL;
    var_dump( $spliceArrayDemo );
    echo '======================================================================'.PHP_EOL.PHP_EOL;
}


{
    echo '==================== Demo Array Destructuring =================='.PHP_EOL;
    $demoArray = array( 'Abel', 'Aiden', 'Jacky', 'JJ' );

    [ '0' => $abel, '2' => $jacky ] = $demoArray;
    echo '$abel= '.$abel.PHP_EOL;
    echo '$jacky= '.$jacky.PHP_EOL;
    echo PHP_EOL;

    [ $abel, $aiden, $jacky ] = $demoArray;
    echo '$abel= '.$abel.PHP_EOL;
    echo '$aiden= '.$aiden.PHP_EOL;
    echo '$jacky= '.$jacky.PHP_EOL;
    
    echo '======================================================================'.PHP_EOL.PHP_EOL;
}
