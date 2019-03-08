
'use strict'; // -> This directive let this script work in modern mode

let cdSymbol = Symbol( "CreatedDate" );

let nullUser = {
	[cdSymbol]: Date.now(),
	[Symbol.toPrimitive] : hint => 'nullUser',
};

let godUser = {
	name: "God",
	age: 10000,
	[cdSymbol]: Date.now(),
	sayHi( value ) { return `Hi~~, ${value}, This is ${this.name}.`; }, // short hand for declaring a method

	[Symbol.toPrimitive] : ( hint ) => {
		if( hint == 'string' )
		{
			let result = 'godUser:';

			// couldn't use 'this' instead of godUser
			for ( let prop in godUser )
			{
				result = result.concat(`\n\t ${prop}: ${godUser[prop]}` ); 
			}

			return result;
		}

		return 0;
	}
};

godUser.isAdmin = true;

let people_1 = new People( 'Jacky', 43 );
let people_2 = People( 'Vivian', 50 );

console.log( `
nullUser: 
${JSON.stringify( nullUser )}
` );

console.log( `
godUser: 
${JSON.stringify( godUser )}
` );

console.log( `
people_1: 
${JSON.stringify( people_1 )}
` );

console.log( `
people_2: 
${JSON.stringify( people_2, null, 2 )}
` );


// People's Constructor
function People( name, age ) {
	if( !(new.target) ) {
		return new People( name, age );
	}

	this.name = name;
	this.age = age;
	this[cdSymbol] = Date.now();
	this[Symbol.toPrimitive] = ( hint ) => {
		if( hint == 'string' )
		{
			let result = 'People:';
			for ( let prop in this )
			{
				result = result.concat(`\n\t ${prop}: ${this[prop]}` );
			}

			return result;
		}

		return 0;
	}
}