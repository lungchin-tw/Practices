<?php 
declare( strict_types=1 );


try {
    $sql = new PDO( "mysql:host=localhost;port=3306;dbname=mchess", "admin", "Qwer123." );
    foreach ( $sql->query( 'SELECT * FROM agent' ) as $row ) {
        print_r( $row );
    }
} catch ( PDOException $e ) {
    var_dump( $e );
    exit();
}