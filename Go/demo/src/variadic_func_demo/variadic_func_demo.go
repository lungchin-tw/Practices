package main

import "fmt"

import "errors"

func variadic_primitives(args ...string) {
	fmt.Printf("[variadic_primitives], args:%#v\n", args)

	for index, arg := range args {
		fmt.Printf("[variadic_primitives], Index:%#v, Arg:%#v\n", index, arg)
	}
}

func variadic_interfaces(args ...interface{}) {
	fmt.Printf("[variadic_interfaces], args=%#v\n", args)

	for index, arg := range args {
		fmt.Printf("[variadic_interfaces], Index=%v, Args=%v, Type=%T\n", index, arg, arg)
	}
}

func main() {
	variadic_primitives("Hi", "Jacky", "Good", "Morning")

	fmt.Println("")

	variadic_interfaces(1, 2.3, "A string", errors.New("An error"))
}
