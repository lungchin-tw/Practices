
'use strict'; // -> This directive let this script work in modern mode


// Benchmarking between getTime() and Time Subtraction
{
	console.log( '========== Benchmarking between getTime() and Time Subtraction ===========' );
	
	// Some JS Engines have Initialization Process
	let b_init_ts = benchmarking( dateSubraction );
	let b_init_tg = benchmarking( dateGetTime );
	
	let b_ts = 0;
	let b_tg = 0;
	for ( let num = 0; num < 10; num++ )
	{
		b_ts += benchmarking( dateSubraction );
		b_tg += benchmarking( dateGetTime );
	}

	console.log( `Benchmarking Result: 
		Subtraction First Benchmark: ${b_init_ts}
		getTime First Benchmark: ${b_init_tg}
		Subtraction Benchmark: ${b_ts}
		getTime Benchmark: ${b_tg}
	` );


	function dateSubraction( d1, d2 ) {
		return ( d2 - d1 );
	}

	function dateGetTime( d1, d2 ) {
		return ( d2.getTime() - d1.getTime() );
	}


	function benchmarking( func ) {
		let d1 = new Date(0);
		let d2 = new Date();

		let start = Date.now();

		for ( let count = 0; count < 1e5; count++ ) {
			func( d1, d2 );
		}

		return ( Date.now() - start );

	}

	console.log( '===========================================================================' );
}