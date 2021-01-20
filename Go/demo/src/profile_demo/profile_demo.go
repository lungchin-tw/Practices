package main

import (
	"fmt"
	"math/rand"
	"os"
	"runtime/pprof"
)

func main() {
	file, err := os.Create("profile_demo.prof")
	if err != nil {
		panic(err)
	}

	pprof.StartCPUProfile(file)
	defer pprof.StopCPUProfile()

	sum := 0
	for i := 0; i < 1000000; i++ {
		sum += rand.Int()
	}

	fmt.Println("Result:", sum)
}
