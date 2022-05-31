package main

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func Sig2String(s string) {

}
func main() {
	fmt.Println("Start Listen Signal...")
	c := make(chan os.Signal, 1)
	signal.Notify(c, syscall.SIGKILL, syscall.SIGINT, syscall.SIGTERM)
	fmt.Printf("syscall.SIGKILL: %v\n", syscall.SIGKILL)
	fmt.Printf("syscall.SIGINT: %v\n", syscall.SIGINT)
	fmt.Printf("syscall.SIGTERM: %v\n", syscall.SIGTERM)
	fmt.Printf("Received Signal: %v\n", <-c)
}
