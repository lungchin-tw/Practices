package main

import "fmt"

func func1() {
	defer fmt.Println("func1")
}

func main() {
	defer fmt.Println("main")

	istrue := true
	if istrue {
		defer fmt.Println("Nest Lv1")
	}

	func1()

	fmt.Println("End")
}
