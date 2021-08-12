package main

import (
	"fmt"
	"math/rand"
	"os"
	"runtime/pprof"
	"runtime/trace"
	"testing"
)

/*
** Try: go tool pprof -http=localhost:6060 {Source}
** Try: go tool trace {Source}
 */

func BenchmarkProfiling(b *testing.B) {
	filename := fmt.Sprintf("%v-%v.prof", b.Name(), b.N)
	b.Log(filename)
	file, err := os.Create(filename)
	if err != nil {
		panic(err)
	}

	pprof.StartCPUProfile(file)
	defer pprof.StopCPUProfile()

	sum := 0
	for i := 0; i < b.N; i++ {
		sum += rand.Int()
	}

	fmt.Println(filename, "Result:", sum)
}

func BenchmarkTrace(b *testing.B) {
	filename := fmt.Sprintf("%v-%v.trace", b.Name(), b.N)
	b.Log(filename)
	file, err := os.Create(filename)
	if err != nil {
		panic(err)
	}

	trace.Start(file)
	defer trace.Stop()

	sum := 0
	for i := 0; i < b.N; i++ {
		sum += rand.Int()
	}

	fmt.Println(filename, "Result:", sum)
}
