<?php
declare(strict_types=1);


require_once __DIR__ . '/vendor/autoload.php';


$smarty = new Smarty();
$smarty->caching = false;
// $smarty->cache_lifetime = 120;
$smarty->template_dir = './templates';
$smarty->compile_dir = './templates_c';

$smarty->assign( 'title', 'Hello Smarty World.' );
$smarty->assign( 'message', 'OOO~~~ Hello World, This is my first Smarty Demo' );

$smarty->display( 'hello_world.tpl' );