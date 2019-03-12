
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
delete godUser.age;

let people_1 = new People( 'Jacky', 43 );
let people_2 = People( 'Vivian', 50 );

console.log( `nullUser[cdSymbol]= ${nullUser[cdSymbol]}` );
console.log( `godUser[cdSymbol]= ${godUser[cdSymbol]}` );
console.log( `people_1[cdSymbol]= ${people_1[cdSymbol]}` );
console.log( `people_2[cdSymbol]= ${people_2[cdSymbol]}` );

printObject( nullUser );
printObject( godUser );
printObject( people_1 );
printObject( people_2 );

console.log( `godUser.sayHi: ${godUser.sayHi( 'Jacky' )}` );

console.log( `========= String Copy ============` );
{
	let originStr = "Hello, World";
	let copyStr = originStr; // clone
	let copyStr2 = originStr; // clone
	console.log( `originStr= ${originStr}, copyStr= ${copyStr}, Is Equal: ${ originStr == copyStr }` );

	copyStr2 = copyStr2.toUpperCase();
	console.log( `copyStr2.toUpperCase(): originStr= ${originStr}, copyStr2= ${copyStr2}, Is Equal: ${ originStr == copyStr2 }` );

	let closure = () => copyStr = copyStr.replace( 'World', 'JavaScript' );
	closure();
	console.log( `${closure}' )` );
	console.log( `originStr= ${originStr}, copyStr= ${copyStr}` );
}
console.log( `==================================` );

console.log( `\n` );

console.log( `========= Object Copy ============` );
{
	let originObj = {
		name: "Origin",
		position: {
			x: 10,
			y: 20,
		},
	};

	let refCopyObj = originObj;
	console.log( `originObj.name= ${originObj.name}, refCopyObj.name= ${refCopyObj.name}` );
	let ref_closure = () => refCopyObj.name = 'RefCopy';
	ref_closure();
	console.log( `${ref_closure}' )` );
	console.log( `originObj.name= ${originObj.name}, refCopyObj.name= ${refCopyObj.name}` );

	console.log( `\n` );

	let deep_closure = () => {
		let copy_result = Object.assign( {}, originObj );
		copy_result.position = Object.assign( {}, copy_result.position );

		copy_result.name = 'DeepCopy';
		copy_result.position.x = 100;
		return copy_result;
	};

	let deepCopy = deep_closure();
	console.log( `${deep_closure}' )` );
	
	console.log( `originObj.name= ${originObj.name}, deepCopy.name= ${deepCopy.name}` );
	console.log( `originObj.position.x= ${originObj.position.x}, deepCopy.position.x= ${deepCopy.position.x}` );
}
console.log( `==================================` );

console.log( '\n' );

console.log( `========= Object to String ============` );
{
	let object_2_string = Object.prototype.toString;
	console.log( `Array: ${object_2_string.call( new Array() )}` );
	console.log( `Number: ${object_2_string.call( new Number() )}` );
	console.log( `console: ${object_2_string.call( console )}` );
	console.log( `console.log: ${object_2_string.call( console.log )}` );
}
console.log( `==================================` );


// People's Constructor
function People( name, age ) {
	console.log( `People: new.target= ${new.target}` );
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

function printObject( in_obj )
{
	console.log( '\n' );
	console.log( `========= printObject ============` );
	console.log( `${in_obj}` );
	console.log( `===========================================` );
}

