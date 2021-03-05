package main

import (
	"context"
	"fmt"
	"time"
)

/*
** Task with timer
 */

func case4() {
	fmt.Println("Running Case 4...")
	ctx, _ := context.WithTimeout(context.Background(), time.Second*3)
	for i := 0; i < 3; i++ {
		go subTask4(context.WithValue(ctx, "ID", i))
	}

	select {
	case <-ctx.Done():
		time.Sleep(time.Second)
		fmt.Println("Case 4 is Done.")
	}
}

func subTask4(ctx context.Context) {
	fmt.Println("Start Running Sub Task:", ctx.Value("ID"))

	counter := 0
	for {
		select {
		case <-ctx.Done():
			fmt.Println("Finished Sub Task:", ctx.Value("ID"), ", Message:", ctx.Err())
			return
		default:
			time.Sleep(time.Second)
			fmt.Println("Sub Task", ctx.Value("ID"), "is Running...", counter)
			counter++
		}
	}
}
