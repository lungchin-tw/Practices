package main

import (
	"testing"
	"time"
)

func fibonacci(n int) []int {
	result := make([]int, n)
	result[0] = 0
	result[1] = 1
	for i := 2; i < n; i++ {
		result[i] = result[i-1] + result[i-2]
	}

	return result
}

func fibonacci_select(t *testing.T, c, quit chan int) {
	x, y := 0, 1
	for {
		select {
		case <-quit:
			t.Log("Received Quit")
			return

		case c <- x:
			t.Log("Before:", x, y)
			x, y = y, x+y
			t.Log("After:", x, y)

		default:
			t.Log("Selected Default.")
			time.Sleep(time.Millisecond)
		}
	}
}

func TestSelect01(t *testing.T) {
	c := make(chan int)
	quit := make(chan int)

	go func() {
		for i := 0; i < 10; i++ {
			t.Logf("Value[%v]=%v", i, <-c)
		}

		t.Log("Sending Quit")
		quit <- 0
	}()

	fibonacci_select(t, c, quit)
	t.Log("All Done")
}
