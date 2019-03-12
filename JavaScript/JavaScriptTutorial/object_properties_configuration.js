
'use strict'; // -> This directive let this script work in modern mode


// 
{
	console.log( '========== Property Flags and Descriptors ===========' );

	let user = {};

	Object.defineProperty( user, "name", {
	  value: "John",
	  writable: true,
	  enumerable: false,
	  configurable: false,
	} );

	let descriptor = Object.getOwnPropertyDescriptor(user, 'name');
	console.log( JSON.stringify(descriptor, null, 2 ) );

	user.name = 'Vivian';
	descriptor = Object.getOwnPropertyDescriptor(user, 'name');
	console.log( JSON.stringify(descriptor, null, 2 ) );

	console.log( '=====================================================' );
}

console.log( '\n' );