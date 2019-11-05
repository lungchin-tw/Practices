package main

import (
	"fmt"
	"math/cmplx"
)


var (
	ToBe bool = false
	MaxInt uint64 = 1<<64 - 1
	z complex128 = cmplx.Sqrt( -5 + 12i )
)


const MAX_MONEY = 9999

const (
	BIG = 1 << 100
	SMALL = BIG >> 99
)

func needFloat( x float64 ) float64 {
	return x
}


func  main()  {
	fmt.Println( "Basic Types:" )
	fmt.Printf( "Type: %T, Value: %v \n", ToBe, ToBe )
	fmt.Printf( "Type: %T, Value: %v \n", MaxInt, MaxInt )
	fmt.Printf( "Type: %T, Value: %v \n", z, z )

	var i int
	var f float64
	var b bool
	var s string
	fmt.Println( "\nZero Values:" )
	fmt.Printf( "Type: %T, Value: %v \n", i, i )
	fmt.Printf( "Type: %T, Value: %v \n", f, f )
	fmt.Printf( "Type: %T, Value: %v \n", b, b )
	fmt.Printf( "Type: %T, Value: %v \n", s, s )

	fmt.Println( "\nType Conversions:" )
	f = float64(MaxInt)
	fmt.Printf( "Type: %T, Value: %v \n", f, f )

	fmt.Println( "\nConstants:" )
	fmt.Printf( "Type: %T, Value: %v \n", MAX_MONEY, MAX_MONEY )
	fmt.Printf( "Type: %T, Value: %v \n", needFloat( BIG ), needFloat( BIG ) )
	// fmt.Printf( "Type: %T, Value: %v \n", BIG, BIG ) will raise exception
	fmt.Printf( "Type: %T, Value: %v \n", SMALL, SMALL )
}