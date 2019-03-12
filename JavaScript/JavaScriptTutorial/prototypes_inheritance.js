
'use strict'; // -> This directive let this script work in modern mode


// Prototypes, Inheritance
{
	let animal = {
		eat: true,
	};

	let rabbit = {
		__proto__: animal,
		jump: true,
	};

	console.log( '============ Prototypes, Inheritance =============' );
	console.log( `rabbit.eat: ${rabbit.eat}` );
	console.log( `rabbit.jump: ${rabbit.jump}` );
	console.log( `LongEarRabbit.prototype.constructor: ${LongEarRabbit.prototype.constructor}` );
	console.log( `LongEarRabbit.prototype.constructor === LongEarRabbit: ${LongEarRabbit.prototype.constructor === LongEarRabbit}` );
	console.log( '===================================================' );

	function LongEarRabbit() {};
}

console.log( '\n' );

// Object.prototype
{
	let obj = {};
	let f = function() {};

	console.log( '============ Object.prototype =============' );
	console.log( `obj: ${obj}` );
	console.log( `obj.__proto__ === Object.prototype: ${obj.__proto__ === Object.prototype}` );
	console.log( `obj.__proto__ : ${obj.__proto__}` );
	console.log( `Object.prototype.__proto__: ${Object.prototype.__proto__}` );
	console.log( `obj.prototype: ${obj.prototype}` );
	console.log( `f: ${f}` );
	console.log( `f.__proto__: ${f.__proto__}` );
	console.log( `f.__proto__ === Function.prototype: ${f.__proto__ === Function.prototype}` );
	console.log( `f.__proto__.__proto__: ${f.__proto__.__proto__}` );
	console.log( `f.__proto__.__proto__ === Object.prototype: ${f.__proto__.__proto__ === Object.prototype}` );
	console.log( `f.__proto__.__proto__ === Object: ${f.__proto__.__proto__ === Object}` );
	console.log( '===========================================' );
}