package math_test

import (
	"math"
	"testing"
)

func TestMath(t *testing.T) {
	x := 12.3456
	t.Logf("math.Round(%v):%v", x, math.Round(x))
	t.Logf("math.Round(%v*100):%v", x, math.Round(x*100))
}
