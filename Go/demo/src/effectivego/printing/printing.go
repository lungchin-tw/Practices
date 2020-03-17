package main

import "fmt"

type TVector2D struct {
	data []int
}

func (self *TVector2D) String() string {
	return fmt.Sprintf("[X=%v, Y=%v]", self.data[0], self.data[1])
}

func main() {
	var x uint64 = 1<<64 - 1
	fmt.Printf("%d, %x, %d, %x\n", x, x, int64(x), int64(x))

	table := map[string]int{
		"x":  1,
		"y":  2,
		"zw": 3,
	}

	fmt.Printf("%v\n", table)
	fmt.Printf("%#v\n", table)
	fmt.Printf("%q\n", table)
	fmt.Printf("%#q\n", table)
	fmt.Printf("%x\n", table)
	fmt.Printf("% x\n", table)
	fmt.Printf("% #x\n", table)

	t := &TVector2D{data: []int{19, 91}}
	fmt.Printf("Vector2D=%v\n", t)
}
