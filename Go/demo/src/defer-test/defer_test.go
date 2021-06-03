package test

import (
	"testing"
)

func func1(t *testing.T) {
	defer t.Log("func1")
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
