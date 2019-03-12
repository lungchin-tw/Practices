
'use strict'; // -> This directive let this script work in modern mode

// Class Patterns Demo
{
	console.log( '========== Class Patterns Demo ===========' );
	/**
	 * Animal Prototype
	 */
	function Animal( name ) {
		this.name = name;
	}

	Animal.prototype.eat = function() {
		return `${this.name} is eating.`
	}

	/**
	 * Rabbit Prototype
	 */
	function Rabbit( name ) {
		this.name = name;
	}

	Rabbit.prototype.jump = function() {
		return `${this.name} is jumping.`
	}

	// Rabbit extends from Animal
	Rabbit.prototype.__proto__ = Animal.prototype; 


	let obj = new Animal( 'An Animal' );
	console.log( obj.eat() );

	let rabbit = new Rabbit( 'A Rabbit' );
	console.log( rabbit.eat() );
	console.log( rabbit.jump() );

	console.log( '==========================================' );
}

console.log( '\n' );

// Classes Demo
{
	class User {
		
		_address = "to be input"; // Class-level properties is a recently feature, so may not support for all JS engines.
		_isAdmin = false; // Class-level properties is a recently feature, so may not support for all JS engines.
		// #privateValue = 100; // a future feature for private value, now the proposal is finished.

		constructor( name ) {
			this.name = name;
		}

		get name() { return this._name;	}
		set name( value ) 
		{ 
			console.log( `User.set name:${value}, length=${value.length}` );
			this._name = value;
		}

		get address() { return this._address; } // Read-Only Property
		get isAdmin() { return this._isAdmin; } // Read-Only Property

		sayHi() {
			return `Hello, ${this.name}.`;
		}
	}

	class AdminUser extends User {
		constructor( name ) {
			super(name);
			this._isAdmin = true;
		}
	}

	console.log( '========== Classes Demo ==================' );
	console.log( `typeof class User: ${typeof User}` );
	console.log( `typeof class User.__proto__: ${typeof User.__proto__}` );
	console.log( `typeof class AdminUser.__proto__.__proto__: ${typeof AdminUser.__proto__.__proto__}` );
	console.log( `typeof class User.prototype: ${typeof User.prototype}` );
	console.log( `typeof class User.prototype.__proto__: ${typeof User.prototype.__proto__}` );
	console.log( `Object.getOwnPropertyNames( class User.prototype ): ${Object.getOwnPropertyNames( User.prototype )}` );
	console.log( `typeof class User.prototype.constructor: ${typeof User.prototype.constructor}` );
	console.log( `AdminUser.__proto__: ${AdminUser.__proto__}` );
	console.log( `AdminUser.__proto__ === User: ${AdminUser.__proto__ === User}` );
	console.log( `AdminUser.prototype: ${AdminUser.prototype}` );
	console.log( `AdminUser.prototype.__proto__: ${AdminUser.prototype.__proto__}` );
	console.log( `AdminUser.prototype.__proto__ === User: ${AdminUser.prototype.__proto__ === User}` );
	console.log( `AdminUser.prototype.__proto__ === User.prototype: ${AdminUser.prototype.__proto__ === User.prototype}` );
	console.log( `AdminUser.__proto__ === Function.prototype: ${AdminUser.__proto__ === Function.prototype}` );
	console.log( `AdminUser.prototype.__proto__ === Function.prototype: ${AdminUser.prototype.__proto__ === Function.prototype}` );
	console.log( `User.prototype.__proto__ === Function.prototype: ${User.prototype.__proto__ === Function.prototype}` );
	console.log( `User.__proto__ === Function.prototype: ${User.__proto__ === Function.prototype}` );

	let jacky = new User( 'Jacky' );
	console.log( `New User: ${jacky.sayHi()}` );
	console.log( `New User's Address: ${jacky.address}` );
	console.log( `New User._isAdmin: ${jacky._isAdmin}` );
	

	console.log( `class AdminUser: ${AdminUser}` );
	let gm001 = new AdminUser( 'GM001' );
	console.log( `gm001.isAdmin: ${gm001.isAdmin}` );
	console.log( `gm001 instanceof AdminUser: ${gm001 instanceof AdminUser}` );
	console.log( `gm001 instanceof User: ${gm001 instanceof User}` );
	console.log( `gm001 instanceof Object: ${gm001 instanceof Object}` );
	console.log( `gm001.__proto__ === AdminUser.prototype: ${gm001.__proto__ === AdminUser.prototype}` );
	console.log( `gm001.__proto__ === User.prototype: ${gm001.__proto__ === User.prototype}` );
	console.log( `gm001.__proto__.__proto__ === User.prototype: ${gm001.__proto__.__proto__ === User.prototype}` );
	console.log( `AdminUser.prototype.isPrototypeOf( gm001 ): ${AdminUser.prototype.isPrototypeOf( gm001 )}` );
	console.log( `User.prototype.isPrototypeOf( gm001 ): ${User.prototype.isPrototypeOf( gm001 )}` );
	console.log( `AdminUser.prototype.isPrototypeOf( jacky ): ${AdminUser.prototype.isPrototypeOf( jacky )}` );
	console.log( `User.prototype.isPrototypeOf( jacky ): ${User.prototype.isPrototypeOf( jacky )}` );
	
	console.log( '==========================================' );
}

console.log( '\n' );

// Demo: Inherited form builtin class
{
	console.log( '========== Demo: Inherited form built-in classes ==================' );
	class PowerArray extends Array {
		isEmpty() { 
			return (this.length <= 0);
		}
	}

	let collection = new PowerArray();
	console.log( `collection.isEmpty(): ${collection.isEmpty()}` );
	
	collection.push( 1, 3, 5, 7, 9 );

	console.log( '================================================================' );
}

console.log( '\n' );

// Demo: Mixin
{
	console.log( '========== Demo: Mixin ==================' );

	let mixinGreeting = {
		sayHi() { return `Hi, ${this.name}.`;},
		sayGoodMorning() { return `sayGoodMorning, ${this.name}.`; },
	}

	class PowerArray extends Array {
		constructor()
		{
			super();
			this._name = 'PowerArray';
		}

		get name() {
			return this._name;
		}

		isEmpty() { 
			return (this.length <= 0);
		}
	}

	Object.assign( PowerArray.prototype, mixinGreeting );

	let power_array = new PowerArray();
	console.log( `power_array.isEmpty(): ${power_array.isEmpty()}` );
	console.log( `power_array.sayHi(): ${power_array.sayHi()}` );
	console.log( `power_array.sayGoodMorning(): ${power_array.sayGoodMorning()}` );
	
	power_array.push( 1, 3, 5, 7, 9 );

	console.log( '================================================================' );
}
