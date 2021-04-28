package print_test

import (
	"fmt"
	"testing"
)

type TVector2D struct {
	data []int
}

func (self *TVector2D) String() string {
	return fmt.Sprintf("[X=%v, Y=%v]", self.data[0], self.data[1])
}

func TestPrinting(t *testing.T) {
	var x uint64 = 1<<64 - 1
	t.Logf("%d, %x, %d, %x", x, x, int64(x), int64(x))

	table := map[string]int{
		"x":  1,
		"y":  2,
		"zw": 3,
	}

	t.Logf("%v", table)
	t.Logf("%#v", table)
	t.Logf("%q", table)
	t.Logf("%#q", table)
	t.Logf("%x", table)
	t.Logf("% x", table)
	t.Logf("% #x", table)

	v := &TVector2D{data: []int{19, 91}}
	t.Logf("Vector2D=%v", v)
}
