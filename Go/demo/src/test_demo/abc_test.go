package main

import (
	"fmt"
	"testing"
)

func TestError(t *testing.T) {
	fmt.Printf("testing.T=%+v:", *t)
	t.Error("TestError")
}

func TestFail(t *testing.T) {
	t.Fail()
}
