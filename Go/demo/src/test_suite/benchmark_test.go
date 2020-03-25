package main

import (
	"fmt"
	"testing"
)

func BenchmarkABC(b *testing.B) {
	fmt.Printf("testing.B=%+v:", *b)
	for index := 0; index < b.N; index++ {
		fmt.Sprintln("BenchmarkABC:", index)
	}
}
