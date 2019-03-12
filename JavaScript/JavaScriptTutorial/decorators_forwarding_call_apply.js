

'use strict'; // -> This directive let this script work in modern mode


// Demo: Transparent Caching
{
	console.log( '========== Transparent Caching ===========' );

	console.log( `Before Decorator, slow: ${slow}` )
	slow = cachingDecorator( slow );
	console.log( `After Decorator, slow: ${slow}` )

	console.log( `slow( 2 ): ${slow( 2 )}` )
	console.log( `slow( 2 ): ${slow( 2 )}` )
	console.log( `slow( 3 ): ${slow( 3 )}` )
	console.log( `slow( 3 ): ${slow( 3 )}` )

	function cachingDecorator( func )
	{
		let cache = new Map();

		return function( x ) {
			if ( cache.has( x ) ) {
				console.log( `cachingDecorator: has cache(${x})` );
				return cache.get( x );
			}

			console.log( `cachingDecorator: do not has cache(${x})` );

			let result = func( x );

			cache.set( x, result );
			return result;
		}
	}

	function slow( x ) {
		return Math.pow( x, x );
	}
	console.log( '==========================================' );
}

console.log( '\n' );

// Demo: func.call
{
	console.log( '========== func.call ===========' );
	let worker = {
		calculate( x ) {
			return Math.pow( x, x );
		},

		execute( x ) {
			return this.calculate( x );
		}
	}

	let executor = cachingDecorator( worker.execute );
	console.log( `executor.call( worker, 2 ): ${executor.call( worker, 2 )}` );
	console.log( `executor.call( worker, 2 ): ${executor.call( worker, 2 )}` );
	console.log( `executor.call( worker, 3 ): ${executor.call( worker, 3 )}` );
	console.log( `executor.call( worker, 3 ): ${executor.call( worker, 3 )}` );

	function cachingDecorator( func )
	{
		let cache = new Map();

		return function( x ) {
			if ( cache.has( x ) ) {
				console.log( `cachingDecorator: has cache(${x})` );
				return cache.get( x );
			}

			console.log( `cachingDecorator: do not has cache(${x})` );

			let result = func.call( this, x );

			cache.set( x, result );
			return result;
		}
	}
	
	console.log( '==========================================' );
}


// Demo: func.apply
{
	console.log( '========== func.apply ===========' );
	let worker = {
		calculate( x, y ) {
			return Math.pow( x, y );
		},

		execute( x, y ) {
			return this.calculate( x, y );
		}
	}

	let executor = cachingDecorator( worker.execute, hashBuilder );
	console.log( `executor.apply( worker, [2, 3] ): ${executor.apply( worker, [2, 3] )}` );
	console.log( `executor.apply( worker, [2, 3] ): ${executor.apply( worker, [2, 3] )}` );
	console.log( `executor.apply( worker, [4, 5] ): ${executor.apply( worker, [4, 5] )}` );
	console.log( `executor.apply( worker, [4, 5] ): ${executor.apply( worker, [4, 5] )}` );

	function cachingDecorator( func, hashBuilder )
	{
		let cache = new Map();

		return function() {
			let key = hashBuilder( arguments );

			if ( cache.has( key ) ) {
				console.log( `cachingDecorator: has cache(${key})` );
				return cache.get( key );
			}

			console.log( `cachingDecorator: do not has cache(${key})` );

			let result = func.apply( this, arguments );

			cache.set( key, result );
			return result;
		}
	}

	function hashBuilder( args ) {
		//return `${args[0]}-${args[1]}`;
		return [].join.call( args, '-' ); // <- Method Borrowing
	}
	
	console.log( '==========================================' );
}