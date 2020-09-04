package main

import (
	"fmt"
)

func case1() {
	fmt.Println("Case 1:")

	c := make(chan int)

	go func() {
		fmt.Println("DONE: Go Routine.")
		c <- 1
		fmt.Println("DONE by Sender.")
	}()

	fmt.Println("DO Something.")
	fmt.Println("DONE By Receiver,", <-c)
}

func case2() {
	fmt.Println("Case 2:")
	c := make(chan int)

	for i := 0; i < 10; i++ {
		go func(i int) {
			fmt.Println("Go Routine,", i)
			c <- i
			fmt.Println("Sender,", i)
		}(i)

	}

	fmt.Println("DO Something.")

	for i := 0; i < 10; i++ {
		fmt.Println("Receiver,", <-c)
	}

	fmt.Println("All Done.")
}

func case3() {
	fmt.Println("Case 3:")
	c := make(chan int, 3)
	fmt.Println("cap(c),", cap(c))

	for i := 0; i < 10; i++ {
		go func(i int) {
			fmt.Println("Go Routine,", i)
			c <- i
			fmt.Println("Sender,", i)
		}(i)

	}

	fmt.Println("DO Something.")

	for i := 0; i < 10; i++ {
		fmt.Println("Receiver,", <-c)
	}

	fmt.Println("All Done.")
}

func case4() {
	fmt.Println("Case 4:")

	queue := make(chan int, 2)
	quit := make(chan int)
	counter := 0
	const TOTAL_NUM = 40

	fmt.Println("cap(queue),", cap(queue))

	for i := 0; i < 3; i++ {
		go func(queue chan int, i int) {
			fmt.Println("Launching Go Routine,", i)
			for value := range queue {
				fmt.Printf("[%v], Value=%v\n", i, value)
				counter++
				if counter >= TOTAL_NUM {
					fmt.Printf("[%v], Sending Quit.\n", i)
					quit <- 1
				}
			}
		}(queue, i)
	}

	for i := 0; i < TOTAL_NUM; i++ {
		queue <- i
	}

	<-quit
	fmt.Println("All Done.")
}

func main() {
	// case1()
	// case2()
	case3()
	// case4()
}
