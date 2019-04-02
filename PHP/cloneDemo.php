<?php
/*
* Experiment Clone Skill
*/

declare( strict_types=1 );


class DemoCloneable {
    public $data = array( 1, 3, 5, 4 );

    public function __clone() {
        //$this->data = $this->data; => array will clone a copy naturally in php, only object need to clone
    }
}

$a = new DemoCloneable();
$b = clone $a;
array_push( $b->data, 2 );
sort( $b->data );

var_dump( $a->data );
var_dump( $b->data );


