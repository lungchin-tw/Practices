package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Println("runtime.GOOS: ", runtime.GOOS)
	fmt.Println("runtime.GOARCH: ", runtime.GOARCH)
	fmt.Println("runtime.GOROOT: ", runtime.GOROOT())
	fmt.Println("runtime.NumCPU: ", runtime.NumCPU())
	fmt.Println("runtime.NumCgoCall: ", runtime.NumCgoCall())
	fmt.Println("runtime.NumGoroutine: ", runtime.NumGoroutine())
	fmt.Println("runtime.Version: ", runtime.Version())
}
