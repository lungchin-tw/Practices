

'use strict'; // -> This directive let this script work in modern mode

import * as lib from './module/my_module.js';

console.log( `import_demo.js, import.meta.url: ${import.meta.url}` );

let msg = lib.sayHi('John');

console.log( msg );
document.body.innerHTML = msg;