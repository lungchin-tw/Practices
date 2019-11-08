package main


import "fmt"


func add( x int, y int ) int  {
	return (x + y)
}

// Shared type & Multiple results
func swap( x, y string )( string, string ) {
	return y, x
}

// Named return values
func split( sum int ) ( x, y int ) {
	x = sum / 10
	y = sum % 10
	return
}


// Variables
var c, python, java bool


func main() {
	fmt.Println( "add( 1, 2 ):", add( 1, 2 ) )

	a, b := swap( "yes", "no" )
	fmt.Println( "swap( \"yes\", \"no\" ):", a, b )

	x, y := split( 17 )
	fmt.Println( "split( 17 ): ", x, y )

	var i int
	fmt.Println( "i, c, python, java: ", i, c, python, java )

	var j, k, text = 10, 20, "test"
	fmt.Println( "j, k, text: ", j, k, text )
}