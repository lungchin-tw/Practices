package main

import "fmt"

func main() {
	var demo []int
	demo = append(demo, []int{3, 4}...)
	fmt.Println(demo)
}
