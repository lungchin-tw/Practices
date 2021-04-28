package flow_control_test

import (
	"fmt"
	"testing"
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

func TestFlowControl(t *testing.T) {
	do_defer()

	t.Log("[do_defer_return],", do_defer_return())

	// value := rand.Int()
	value := 0

	if value > 1 {
		do_panic()
		t.Log("After do_panic()")
	}

	do_recover(3)
	t.Log("After do_recover()")
}
