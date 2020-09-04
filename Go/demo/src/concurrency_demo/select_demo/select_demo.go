package main

import (
	"fmt"
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

func fibonacci_select(c, quit chan int) {
	x, y := 0, 1
	for {
		select {
		case <-quit:
			fmt.Println("Received Quit")
			return

		case c <- x:
			fmt.Println("Before:", x, y)
			x, y = y, x+y
			fmt.Println("After:", x, y)

		default:
			fmt.Println("Selected Default.")
			time.Sleep(time.Millisecond)
		}
	}
}

func case1() {
	c := make(chan int)
	quit := make(chan int)

	go func() {
		for i := 0; i < 10; i++ {
			fmt.Printf("Value[%v]=%v\n", i, <-c)
		}

		fmt.Println("Sending Quit")
		quit <- 0
	}()

	fibonacci_select(c, quit)
	fmt.Println("All Done")
}

func case2() {
	tick := time.Tick(time.Second)
	boom := time.Tick(time.Second * 10)

	for {
		select {
		case <-boom:
			fmt.Println("BOOM!!!")
			return

		default:
			fmt.Println("Tick,", <-tick)
		}
	}

	fmt.Println("All Done")
}

func main() {
	// fmt.Println("Result:", fibonacci(20))

	// case1()
	case2()
}
