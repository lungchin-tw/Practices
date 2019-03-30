<?php
/*
* Experiment Advanced Skill
*/

declare( strict_types=1 );


class DemoClass {
    public $publicInt = 100;
    private $_privateInt = 200;
    private $_privateString = 'Demo';

    public function getPrivateInt() : int {
        return $this->_privateInt;
    }

    private function getPrivateString() : string {
        return $this->_privateString;
    }
}


echo json_encode( new DemoClass() );