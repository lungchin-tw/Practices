package main

import (
	"context"
	"fmt"
	"os"
	"os/signal"
	"syscall"
	"time"
)

/*
** Nest Task
 */

func main() {
	fmt.Println("Running Case 3...")
	ctx, cancel := context.WithCancel(context.Background())
	for i := 0; i < 3; i++ {
		go subTask3(uint64(i), ctx)
	}

	shutdown := make(chan os.Signal, 1)
	signal.Notify(shutdown, syscall.SIGKILL, syscall.SIGINT, syscall.SIGTERM)
	select {
	case <-shutdown:
		cancel()
		time.Sleep(3 * time.Second)
		fmt.Println("Case 3 is Done.")
	}

}

func subTask3(id uint64, ctx context.Context) {
	fmt.Println("Start Running Sub Task:", id)

	counter := 0
	for {
		select {
		case <-ctx.Done():
			fmt.Println("Finished Sub Task:", id, ", Message:", ctx.Err())
			return
		default:
			time.Sleep(time.Second)
			fmt.Println("Sub Task", id, " is Running...", counter)
			counter++
		}
	}
}
