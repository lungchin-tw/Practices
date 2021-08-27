package main

import (
	"math/rand"
	"testing"
	"time"
)

func TestSelect03(t *testing.T) {
	ca := make(chan int, 5)
	cb := make(chan int, 2)
	quit := time.Tick(time.Second * 3)

	go func() {
		counter := 0
		for {
			counter++
			t.Log("cb <-:", counter)
			cb <- rand.Int()
			t.Log("ca <-:", counter)
			ca <- rand.Int()

		}
	}()

	for {
		select {
		case <-ca:
			t.Log("<-ca")
		case <-quit:
			t.Log("quit")
			return
		}
	}
}
