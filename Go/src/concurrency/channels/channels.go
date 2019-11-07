package main

import "fmt"

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

func main() {
	s := []int{7, 2, 8, -9, 4, 0}
	fmt.Println("s[:len(s)/2]=", s[:len(s)/2])

	c := make(chan int)
	go sum(s[:len(s)/2], c)
	go sum(s[len(s)/2:], c)
	x := <-c
	fmt.Println("x := <-c, x=", x)
	y := <-c
	fmt.Println("y := <-c, y=", y)

	fmt.Println("\nBuffered Channels:")

	ch := make(chan int, 2)
	ch <- 1
	ch <- 2
	// ch <- 3 This will raise an exception!!!
	fmt.Println("<-ch: ", <-ch)
	fmt.Println("<-ch: ", <-ch)
	// fmt.Println("<-ch: ", <-ch) This will raise an exception
	ch <- 1
	fmt.Println("<-ch: ", <-ch)

	// ch <- 1
	go sum(s[:len(s)/2], ch)
	// ch <- 2
	go sum(s[len(s)/2:], ch)

	{
		x, ok := <-ch
		fmt.Printf("x := <-ch, x=%v, ok=%v\n", x, ok)
		y, ok := <-ch
		fmt.Printf("y := <-ch, y=%v, ok=%v\n", y, ok)
	}
}
