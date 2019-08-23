<?php 
declare( strict_types=1 );


class foo 
{
    public function __destruct()
    {
        echo __METHOD__.':'.__LINE__.PHP_EOL;
    }
}


function shutdown() 
{
    echo __FUNCTION__.':'.__LINE__.PHP_EOL;
}

new foo();
register_shutdown_function( 'shutdown' );

exit();
echo 'This will not be output.';