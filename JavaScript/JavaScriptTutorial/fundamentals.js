
'use strict'; // -> This directive let this script work in modern mode

let message = 'Hello New World';
const greeting = `Jacky, ${message}`;

let doAlert = true;

console.log( message ); 
console.log( doAlert ); 
console.log( typeof( message) );

console.log( `Boolean("0") : ${ Boolean("0") }` );
console.log( `null == undefined : ${ null == undefined }` );
console.log( `null === undefined : ${ null === undefined }` );
console.log( `null > 0 : ${ null > 0 }` );
console.log( `null == 0 : ${ null == 0 }` );
console.log( `null >= 0 : ${ null >= 0 }` );
console.log( `undefined > 0 : ${ undefined > 0 }` );
console.log( `undefined < 0 : ${ undefined < 0 }` );
console.log( `undefined == 0 : ${ undefined == 0 }` );
//alert( greeting );

