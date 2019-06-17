<?php
declare( strict_types=1 );

namespace jacky{
    require_once 'base_class.php';
    class ExtendedClass extends \BaseClass {

        static function printSymbol() {
            echo 'self::class: '.self::class.PHP_EOL;
            echo 'static::class: '.static::class.PHP_EOL;
            echo '__CLASS__: '.__CLASS__.PHP_EOL;
            echo '__METHOD__: '.__METHOD__.PHP_EOL;
            echo '__FUNCTION__: '.__FUNCTION__.PHP_EOL;
        }

        function __construct() {
            parent::__construct();
            echo self::class.': '.__METHOD__.PHP_EOL;
        }

        public function getNum() : int {
            echo __METHOD__.PHP_EOL;
            return 1010;
        }
    }
}