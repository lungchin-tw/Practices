package main

import "fmt"

import "time"

func demo_unbuffered_channels() {
	ch := make(chan string)
	counter := 10

	go func() {
		for index := 0; index < counter; index++ {
			<-time.After(time.Millisecond * 500)
			fmt.Println("Sending", index)
			ch <- fmt.Sprintln("hello world", index)
		}
		fmt.Println("All Send")
	}()

	<-time.After(time.Second * 3)

	for index := 0; index < counter; index++ {
		fmt.Println("Recieving", index)
		fmt.Println(<-ch)
	}
	fmt.Println("All Received")

	<-time.After(time.Second * 3)
	fmt.Println("After 3 seconds")
}

func demo_buffered_channels() {
	ch := make(chan string, 3)
	counter := 10

	go func() {
		for index := 0; index < counter; index++ {
			<-time.After(time.Millisecond * 500)
			fmt.Println("Sending", index)
			ch <- fmt.Sprintln("hello world", index)
		}
		close(ch)
		fmt.Println("All Send")
	}()

	<-time.After(time.Second * 3)

	/*
	** Rcv Method A
	 */
	// for index := 0; index < counter; index++ {
	// 	fmt.Println("Recieving", index)
	// 	fmt.Println(<-ch)
	// }

	/*
	** Rcv Method B : range with close(ch)
	 */
	for msg := range ch {
		fmt.Println("Received", msg)
	}
	fmt.Println("All Received")

	<-time.After(time.Second * 3)
	fmt.Println("After 3 seconds")
}

func demo_non_blocking_read() {
	ch := make(chan string)

	go func() {
		ch <- "Hello, World~~"
	}()

	do_select := func() {
		select {
		case msg := <-ch:
			fmt.Println(msg)
		default:
			fmt.Println("No Message")
		}
	}

	do_select()

	<-time.After(time.Second * 3)

	do_select()
}

func main() {
	// demo_unbuffered_channels()
	// demo_buffered_channels()
	demo_non_blocking_read()
}
