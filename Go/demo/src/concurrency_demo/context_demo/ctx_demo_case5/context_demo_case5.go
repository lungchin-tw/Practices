package main

import (
	"context"
	"fmt"
	"time"
)

const MAX_INT = 5

func genInt(ctx context.Context) <-chan int {
	ch := make(chan int)

	go func() {
		var n int
		for {
			select {
			case <-ctx.Done():
				fmt.Println("<-ctx.Done()")
				return
			case ch <- n:
				n++
				fmt.Println("ch <- n:", n)
				time.Sleep(time.Second)
			}
		}
	}()

	return ch
}

func main() {
	fmt.Println("Running Case 5...")
	ctx, cancel := context.WithCancel(context.Background())
	defer cancel()

	for n := range genInt(ctx) {
		fmt.Println("genInt:", n)
		if n == MAX_INT {
			cancel()
			break
		}
	}

	time.Sleep(time.Second)
	fmt.Println("Case 5 is Done.")
}
