<?php 

$prototype = new stdClass();
$prototype->str = '123';

$list = array();
array_push( $list, clone $prototype );

print_r( $list );

?>