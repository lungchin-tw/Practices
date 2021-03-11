package main

import (
	"context"
	"fmt"
	"time"
)

func task(id uint64, duration time.Duration, cancel context.CancelFunc) {
	fmt.Println("Task", id, "Start...")
	time.Sleep(duration)
	fmt.Println("Task", id, "Done.")
	cancel()
}

const (
	NUM_TASK          = 5
	MAX_TASK_DURATION = NUM_TASK + 3
)

func main() {
	fmt.Println("Running Case 2...")
	context_list := []context.Context{}
	for i := 0; i < NUM_TASK; i++ {
		ctx, cancel := context.WithCancel(context.Background())
		id := uint64(i)
		context_list = append(context_list, ctx)
		go task(id, time.Duration(((MAX_TASK_DURATION - i) * int(time.Second))), cancel)
	}

	for index, value := range context_list {
		fmt.Println("Index:", index, ", Value:", value, ", <-:", <-value.Done())
	}
	fmt.Println("Case 2 is Done.")
}
