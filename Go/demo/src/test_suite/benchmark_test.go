package main

import "testing"

import "fmt"

func BenchmarkABC(b *testing.B) {
	fmt.Printf("testing.B=%+v:", *b)
	for index := 0; index < 10; index++ {
		fmt.Println("BenchmarkABC:", index)
	}
}
