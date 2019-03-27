<?php
declare( strict_types=1 );

namespace jacky{
    require_once 'base_class.php';
    class ExtendedClass extends \BaseClass {
        function __construct() {
            parent::__construct();
            echo self::class.': '.__METHOD__.PHP_EOL;
        }

        public function getNum() : int {
            return 1010;
        }
    }
}