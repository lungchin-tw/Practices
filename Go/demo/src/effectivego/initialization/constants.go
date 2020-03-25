package main

import "fmt"

const (
	NONE int = iota * -1
	FIRST
	SECOND
	THIRD
)

func init() {
	fmt.Println("func init()")
}

func main() {
	fmt.Println("func main()")

	fmt.Println("NONE=", NONE)
	fmt.Println("FIRST=", FIRST)
	fmt.Println("SECOND=", SECOND)
	fmt.Println("THIRD=", THIRD)
}
