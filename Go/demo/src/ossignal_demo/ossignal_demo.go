package main

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	fmt.Println("Start Listen Signal...")
	c := make(chan os.Signal, 1)
	signal.Notify(c, syscall.SIGKILL, syscall.SIGINT, syscall.SIGTERM)
	fmt.Printf("syscall.SIGKILL: %x\n", syscall.SIGKILL)
	fmt.Printf("syscall.SIGINT: %x\n", syscall.SIGINT)
	fmt.Printf("syscall.SIGTERM: %x\n", syscall.SIGTERM)
	fmt.Printf("Received Signal: %x\n", <-c)
}
