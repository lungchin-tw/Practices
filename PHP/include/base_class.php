<?php
declare( strict_types=1 );

require_once 'interface.php';


class BaseClass implements IInterface {
    public const CONST_BASE_VALUE = 'ConstBaseValue';

    public function getNum() : int {
        return 101;
    }
}