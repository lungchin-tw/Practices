
'use strict'; // -> This directive let this script work in modern mode

let message = 'Hello New World';
let doAlert = false;

console.log( message );
console.log( `Do Alert: ${doAlert}` ); 
console.log( `typeof(message): ${typeof(message)}` );
console.log( `typeof(null): ${typeof(null)}` );
console.log( `typeof(undefined): ${typeof(undefined)}` );
console.log( `typeof(function): ${typeof(function(){})}` );

console.log( `Boolean("0") : ${ Boolean("0") }` );
console.log( `null == undefined : ${ null == undefined }` );
console.log( `null === undefined : ${ null === undefined }` );
console.log( `null > 0 : ${ null > 0 }` );
console.log( `null == 0 : ${ null == 0 }` );
console.log( `null >= 0 : ${ null >= 0 }` );
console.log( `undefined > 0 : ${ undefined > 0 }` );
console.log( `undefined < 0 : ${ undefined < 0 }` );
console.log( `undefined == 0 : ${ undefined == 0 }` );

let your_name = prompt( "What's you name?" );


if ( doAlert == true )
{
	alert( buildGreeting( your_name ) );
}
else
{
	console.log( buildGreeting( your_name ) );
}

// Function Expression
let cancel = function() { console.log( "Bad Mood Today" ); };

console.log( "========= cancel vs. cancel() =========" );
console.log( `cancel=${cancel}` );
console.log( `cancel()=${cancel()}` );
console.log( "=======================================" );

debugger;

askMood(
	"Are you in a good mood today?"
	, function() { console.log( "Good Mood Today" ); }
	, cancel
);

let num = prompt( "Input a Square Root" );
let square = n => n * n; // Function Expression
console.log( `Square of ${num} = ${square(num)}` );


/*
** Function Declaration
*/

function buildGreeting( name )
{
	return `${name}, ${message}`;
}


function askMood( context, yes, no )
{
	confirm( context ) ? yes() : no();
}