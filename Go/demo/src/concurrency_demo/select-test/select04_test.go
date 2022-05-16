package main

import (
	"math/rand"
	"testing"
)

/*
** Sends and receives on nil channels block.
** Select never selects a blocking case.
 */
func TestSelectNil(t *testing.T) {
	a := make(chan string)
	b := make(chan string)
	go func() {
		t.Log("a <- \"a\"")
		a <- "a"
	}()

	go func() {
		t.Log("b <- \"b\"")
		b <- "b"
	}()

	if (rand.Int() & 0x01) == 0 {
		a = nil
		t.Log("nil a")
	} else {
		b = nil
		t.Log("nil b")
	}

	select {
	case s := <-a:
		t.Log("got", s)
	case s := <-b:
		t.Log("got", s)
	}
}
