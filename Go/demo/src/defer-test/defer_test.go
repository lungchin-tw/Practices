package test

import (
	"testing"
)

func func1(t *testing.T) {
	defer t.Log("func1")
}

func func2(t *testing.T) *testing.T {
	t.Log("func2")
	return t
}

func TestDeferSubFunc(t *testing.T) {
	t.Log("TestDeferSubFunc-Start")
	defer func2(t).Log("TestDeferSubFunc-End")
	t.Log("TestDeferSubFunc-Middle")
}

func TestDefer(t *testing.T) {
	defer t.Log("main")

	istrue := true
	if istrue {
		defer t.Log("Nest Lv1")
	}

	func1(t)

	t.Log("End")
}
