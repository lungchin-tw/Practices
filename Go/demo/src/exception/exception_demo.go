package main

import (
	"errors"
	"fmt"
)

func main() {
	err := errors.New("Access DB error!!!")
	fmt.Printf("err: %v\n", err)
	fmt.Printf("err: %+v\n", err)
	fmt.Printf("err: %v\n", err.Error())
}
