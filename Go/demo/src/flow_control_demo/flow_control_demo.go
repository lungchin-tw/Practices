package main

import (
	"fmt"
)

func do_defer() {
	i := 0
	defer fmt.Println("[do_defer], Defer:", i)
	i++
	fmt.Println("[do_defer], No Defer:", i)
}

func do_defer_return() (i int) {
	defer func() {
		i++
	}()

	return 1
}

func do_panic() {
	panic("do_panic")
}

func recur(value int) {
	if value < 0 {
		panic("[recur], value < 0")
	}

	defer fmt.Println("[recur], Defer:", value)
	fmt.Println("[recur], value:", value)

	recur(value - 1)
}

func do_recover(value int) {
	defer func() {
		if r := recover(); r != nil {
			fmt.Printf("[do_recover], Recover:{ Type:%T, Value:%#v}\n", r, r)
		}
	}()

	fmt.Println("[do_recover], Begin")
	recur(value)
	fmt.Println("[do_recover], End")
}

func main() {
	do_defer()

	fmt.Println("[do_defer_return],", do_defer_return())

	if 1 == 2 {
		do_panic()
		fmt.Println("After do_panic()")
	}

	do_recover(3)
	fmt.Println("After do_recover()")
}
