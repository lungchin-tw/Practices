package main

import "math"

import "fmt"

func main() {
	x := 12.3456
	fmt.Printf("math.Round(%v):%v\n", x, math.Round(x))
	fmt.Printf("math.Round(%v*100):%v\n", x, math.Round(x*100))
}
