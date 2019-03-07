
'use strict'; // -> This directive let this script work in modern mode

// exercise e description for numbers
{
	console.log( '========== Exercise Number Description ===========' );
	let value = 1.9e3;

	console.log( `
		value = 1.9e3 = ${value}
		binary of value = ${value.toString(2)}
		octal of value = ${value.toString(8)}
		hex of value = ${value.toString(16)}
	` );
	
	console.log( '==================================================' );
}

console.log( '\n' );

// Exercise Functions of Math
{
	console.log( '========== Exercise Functions of Math ===========' );

	console.log( `
		Math.floor( 3.1 ) = ${Math.floor( 3.1 )}
		Math.floor( -1.1 ) = ${Math.floor( -1.1 )}
		Math.ceil( 3.1 ) = ${Math.ceil( 3.1 )}
		Math.ceil( -1.1 ) = ${Math.ceil( -1.1 )}
		Math.round( 3.1 ) = ${Math.round( 3.1 )}
		Math.round( 3.5 ) = ${Math.round( 3.5 )}
		Math.round( -1.1 ) = ${Math.round( -1.1 )}
		Math.round( -1.5 ) = ${Math.round( -1.5 )}
		Math.round( -1.6 ) = ${Math.round( -1.6 )}
		Math.trunc( 3.1 ) = ${Math.trunc( 3.1 )}
		Math.trunc( -1.1 ) = ${Math.trunc( -1.1 )}
	` );
	
	console.log( '==================================================' );
}

console.log( '\n' );

// Exercise Imprecise Calculations
{
	console.log( '========== Exercise Imprecise Calculations ===========' );
	let a = 0.1;
	let b = 0.2;

	console.log( `
		a = ${a}, a.toFixed(20) = ${a.toFixed(20)}
		b = ${b}, b.toFixed(20) = ${b.toFixed(20)}
		(a + b) = ${a+b}, (a+b).toFixed(20) = ${(a+b).toFixed(20)}
		((a + b) == 0.3): ${(a+b) == 0.3}, +(a+b).toFixed(2) == 0.3: ${(+(a+b).toFixed(2) == 0.3)}
		9999999999999999 = ${9999999999999999}
	` );

	console.log( '==================================================' );
}

// Exercise Bitwise NOT ~
{
	console.log( '========== Exercise Bitwise NOT ~ ===========' );
	
	console.log( `
		~2: ${~2}
		~1: ${~1}
		~0: ${~0}
		~-1: ${~-1}
	` );

	console.log( '==================================================' );
}