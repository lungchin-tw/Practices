package main

import (
	"fmt"
	"runtime"
	"time"
)

func main() {
	fmt.Println("Goroutines:")

	go say("hello")

	for index := 0; index < 10; index++ {
		go fmt.Println("go index: ", index)
		fmt.Println("runtime.NumGoroutine: ", runtime.NumGoroutine())
	}

	say("world")

	fmt.Println("/nEnd of main()")

}

func say(value string) {
	for index := 0; index < 10; index++ {
		time.Sleep(100 * time.Millisecond)
		fmt.Printf("say: %v, index=%v\n", value, index)
		fmt.Println("say: runtime.NumGoroutine: ", runtime.NumGoroutine())
	}
}
