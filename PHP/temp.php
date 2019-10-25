<?php 
declare( strict_types=1 );

$obj = new stdClass();

echo is_null( $obj ) ?: '$obj is not null.';