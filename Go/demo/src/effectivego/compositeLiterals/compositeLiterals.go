package main

import "fmt"

const (
	Enone = 0
	Eio   = 2
)

func main() {
	a := [...]string{Enone: "no error", Eio: "Eio"}
	fmt.Printf("[...]string=%#v", a)
}
