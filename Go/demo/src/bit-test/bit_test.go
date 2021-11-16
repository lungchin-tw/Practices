package bittest

import "testing"

func TestBitOperation(t *testing.T) {
	v := (0 | 0x1) | 0x4 | 0x8
	t.Logf("%d, %x, %o, %b", v, v, v, v)

	v ^= 0x4
	t.Logf("%d, %x, %o, %b", v, v, v, v)
}
