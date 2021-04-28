package slice_test

import (
	"testing"
)

func TestSlice(t *testing.T) {
	a := [...]int{1, 2, 3, 4, 5, 6}
	t.Logf("a=%#v", a)

	s := a[1:4]
	t.Logf("s=%#v, len=%v, cap=%v", s, len(s), cap(s))

	s = append(s, 10, 11, 12, 13)
	t.Logf("s=%#v, len=%v, cap=%v", s, len(s), cap(s))
	t.Logf("a=%#v", a)

	s = s[1:4]
	t.Logf("s=%#v, len=%v, cap=%v", s, len(s), cap(s))

	dynamic := []int{
		5: 5,
		2: 2,
	}
	t.Logf("dynamic=%#v, len=%v, cap=%v", dynamic, len(dynamic), cap(dynamic))
}
