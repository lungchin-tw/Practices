<?php 
declare( strict_types=1 );


trait TraitDemo {
    function getDesc() : string {
        return __METHOD__;
    }
}


class Base {
    use TraitDemo;

    public function sayHello() {
        echo 'Hello';
    }
}

echo '[simple trait](new Base())->getDesc(): '.(new Base())->getDesc();
echo PHP_EOL.PHP_EOL;



/*
trait Precedence Order:  Extended Class Method > Trait Method > Base Class Method
*/

trait TraitSayHello {
    public function sayHello() {
        parent::sayHello();
        echo ', World!';
    }
}

class Derived extends Base {
    use TraitSayHello;
}

echo '[trait Precedence Order I](new Derived())->sayHello(): ';
(new Derived())->sayHello();
echo PHP_EOL.PHP_EOL;


class DerivedII extends Base {
    use TraitSayHello;

    public function sayHello() {
        echo __METHOD__;
    }
}


echo '[trait Precedence Order II](new DerivedII())->sayHello(): ';
(new DerivedII())->sayHello();
echo PHP_EOL.PHP_EOL;


/**
 * Multiple Traits
 */
trait CarTrait {
    public function drive() {
        echo __METHOD__;
    }
}

trait AirplaneTrait {
    public function fly() {
        echo __METHOD__;
    }
}

class Vehicle {
    use CarTrait, AirplaneTrait;
}

$vehicle = new Vehicle();
$vehicle->drive();
echo PHP_EOL;
$vehicle->fly();
echo PHP_EOL;