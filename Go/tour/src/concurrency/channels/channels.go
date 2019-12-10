package main

import (
	"fmt"
	"runtime"
	"time"
)

func printFrames() {
	pc := make([]uintptr, 15)
	n := runtime.Callers(2, pc)
	frames := runtime.CallersFrames(pc[:n])
	frame, _ := frames.Next()
	fmt.Printf("%s:%d, %s\n", frame.File, frame.Line, frame.Function)
}

func sum(s []int, c chan int) {
	fmt.Printf("s=%v, c: Type=%T, Value=%v\n", s, c, c)
	sum := 0
	for index, value := range s {
		fmt.Printf("sum=%v, value=%v, index=%v\n", sum, value, index)
		sum += value
	}

	fmt.Println("c <- sum, sum=", sum)
	c <- sum
}

func range_and_close(num int, c chan int) {
	printFrames()
	fmt.Printf("num=%v, c=%v\n", num, c)
	for index := 0; index < num; index++ {
		fmt.Println("range_and_close: runtime.NumGoroutine =", runtime.NumGoroutine())
		c <- index
	}

	close(c)
}

func select_demo(c, quit chan int) {
	printFrames()

	x := 0
	for {
		select {
		case c <- x:
			fmt.Println("x =", x)
			x += 1
		case <-quit:
			fmt.Println("<-quit")
			return
		}
	}
}

func default_selection() {
	printFrames()
	tick := time.Tick(1000 * time.Millisecond)
	boom := time.Tick(10000 * time.Millisecond)

	for {
		select {
		case <-tick:
			fmt.Println("tick...")
		case <-boom:
			fmt.Println("BOOM!!!")
			return
		default:
			fmt.Println("Default...")
			time.Sleep(500 * time.Millisecond)
		}
	}
}

func main() {
	// s := []int{7, 2, 8, -9, 4, 0}
	// fmt.Println("s[:len(s)/2]=", s[:len(s)/2])

	// c := make(chan int)
	// go sum(s[:len(s)/2], c)
	// go sum(s[len(s)/2:], c)
	// x := <-c
	// fmt.Println("x := <-c, x=", x)
	// y := <-c
	// fmt.Println("y := <-c, y=", y)

	// fmt.Println("\nBuffered Channels:")

	// ch := make(chan int, 2)
	// ch <- 1
	// ch <- 2
	// // ch <- 3 This will raise an exception!!!
	// fmt.Println("<-ch: ", <-ch)
	// fmt.Println("<-ch: ", <-ch)
	// // fmt.Println("<-ch: ", <-ch) This will raise an exception
	// ch <- 1
	// fmt.Println("<-ch: ", <-ch)

	// // ch <- 1
	// go sum(s[:len(s)/2], ch)
	// // ch <- 2
	// go sum(s[len(s)/2:], ch)

	// {
	// 	x, ok := <-ch
	// 	fmt.Printf("x := <-ch, x=%v, ok=%v\n", x, ok)
	// 	y, ok := <-ch
	// 	fmt.Printf("y := <-ch, y=%v, ok=%v\n", y, ok)
	// 	// y, ok = <-ch This will raise an exception
	// 	// fmt.Printf("y := <-ch, y=%v, ok=%v\n", y, ok)
	// }

	// {
	// 	fmt.Println("\nRange and Close:")
	// 	c := make(chan int, 10)
	// 	go range_and_close(cap(c), c)
	// 	for index := range c {
	// 		fmt.Println("index: ", index)
	// 	}
	// }

	{
		fmt.Println("\nSelect:")
		c := make(chan int)
		quit := make(chan int)
		go func() {
			for index := 0; index < 10; index++ {
				fmt.Printf("index=%v, <-c:%v\n", index, <-c)
			}
			quit <- 0
		}()

		select_demo(c, quit)
	}

	// {
	// 	fmt.Println("\nDefault Selection:")
	// 	default_selection()
	// }
}
