

'use strict'; // -> This directive let this script work in modern mode

import {sayHi} from './module/my_module.js';

let msg = sayHi('John');

console.log( msg );
document.body.innerHTML = msg;