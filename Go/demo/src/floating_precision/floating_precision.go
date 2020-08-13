package main

import "fmt"

func main() {
	f := 1.0
	for f < 2.0 {
		fmt.Printf("Float: %v, Int: %v\n", f, int64(f))
		f += 0.1
	}
}
