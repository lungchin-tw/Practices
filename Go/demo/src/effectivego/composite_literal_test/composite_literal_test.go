package composite_literal_test

import (
	"testing"
)

const (
	Enone = 0
	Eio   = 2
)

func TestCompositeLiteral(t *testing.T) {
	a := [...]string{Enone: "no error", Eio: "Eio"}
	t.Logf("[...]string=%#v", a)
}
