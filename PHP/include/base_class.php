<?php
declare( strict_types=1 );

require_once 'interface.php';


class BaseClass implements IInterface {
    private const CONST_BASE_CLASS_DESC = 'class BaseClass implements IInterface';

    static function printSymbol() {
        echo 'Desc: '.self::CONST_BASE_CLASS_DESC.PHP_EOL;
        echo 'self::class: '.self::class.PHP_EOL;
        echo 'static::class: '.static::class.PHP_EOL;
        echo '__CLASS__: '.__CLASS__.PHP_EOL;
        echo '__METHOD__: '.__METHOD__.PHP_EOL;
        echo '__FUNCTION__: '.__FUNCTION__.PHP_EOL;
    }

    function __construct() {
        echo self::class.': '.__METHOD__.PHP_EOL;
    }

    public const CONST_BASE_VALUE = 'ConstBaseValue';

    public function getNum() : int {
        return 101;
    }
}