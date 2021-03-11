package main

import (
	"fmt"
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

func main() {
	fmt.Println("MIN:", MIN)
	fmt.Println("ONE:", ONE)
	fmt.Println("MAX:", MAX)
	for i := MIN; i < MAX; i++ {
		fmt.Println(i)
	}

	fmt.Println("int(1) == ONE:", int(1) == ONE)
	fmt.Println("uint(1) == ONE:", uint(1) == ONE)
	fmt.Println("int64(1) == ONE:", int64(1) == ONE)
	fmt.Println("uint64(1) == ONE:", uint64(1) == ONE)

	fmt.Println("")
	fmt.Println("BitFlag1:", BitFlag1)
	fmt.Println("BitFlag2:", BitFlag2)
	fmt.Println("BitFlag3:", BitFlag3)
	fmt.Println("BitFlag4:", BitFlag4)
	fmt.Println("BitFlags:", BitFlag4|BitFlag1)
}
