package main

import "fmt"

const (
	ONE = iota + 1
	TWO
	THREE
	FOUR
	MAX
	MIN = ONE
)

func main() {
	fmt.Println("MIN:", MIN)
	fmt.Println("ONE:", ONE)
	fmt.Println("MAX:", MAX)
	for i := MIN; i < MAX; i++ {
		fmt.Println(i)
	}
}
