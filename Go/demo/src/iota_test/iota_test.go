package iota_test

import (
	"testing"
)

const (
	ONE = iota + 1
	TWO
	THREE
	FOUR
	MAX
	MIN = ONE
)

type TBitFlag uint64

const (
	BitFlag1 TBitFlag = 1 << iota
	BitFlag2
	BitFlag3
	BitFlag4
)

func TestIOTA(t *testing.T) {
	t.Log("MIN:", MIN)
	t.Log("ONE:", ONE)
	t.Log("MAX:", MAX)
	for i := MIN; i < MAX; i++ {
		t.Log(i)
	}

	t.Log("int(1) == ONE:", int(1) == ONE)
	t.Log("uint(1) == ONE:", uint(1) == ONE)
	t.Log("int64(1) == ONE:", int64(1) == ONE)
	t.Log("uint64(1) == ONE:", uint64(1) == ONE)

	t.Log("")
	t.Log("BitFlag1:", BitFlag1)
	t.Log("BitFlag2:", BitFlag2)
	t.Log("BitFlag3:", BitFlag3)
	t.Log("BitFlag4:", BitFlag4)
	t.Log("BitFlags:", BitFlag4|BitFlag1)
}
