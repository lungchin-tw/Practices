package main

import (
	"errors"
	"fmt"
	"log"
)

func DoFatal(err error) {
	defer fmt.Println("defer DoFatal")
	log.Fatalf("Err:%v", err)
}

func DoPanic(err error) {
	defer fmt.Println("defer DoPanic")
	log.Panicf("Err:%v", err)
}

func main() {
	defer fmt.Println("defer main")

	err := errors.New("Access DB error!!!")
	fmt.Printf("err: %v\n", err)
	fmt.Printf("err: %+v\n", err)
	fmt.Printf("err: %v\n", err.Error())
	fmt.Printf("errors.Unwrap: %+v\n", errors.Unwrap(err))

	// DoFatal(err)
	// fmt.Println("After Fatal")

	DoPanic(err)
	fmt.Println("After Panic")
}
