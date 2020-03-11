package main

import (
	"fmt"
	"math"
	"strings"
)

type Vertex struct {
	X int
	Y int
}

func main() {

	fmt.Println("Pointers:")

	i := 42
	j := 2701

	p := &i
	fmt.Println("< p := &i >:")
	fmt.Printf("Type of p:%T, Value of p:%v\n", p, p)
	fmt.Printf("Type of *p:%T, Value of *p:%v\n", *p, *p)

	fmt.Println("")

	*p = j
	fmt.Println("< *p = j >:")
	fmt.Printf("Type of p:%T, Value of p:%v\n", p, p)
	fmt.Printf("Type of *p:%T, Value of *p:%v\n", *p, *p)
	fmt.Printf("i: %v\n", i)

	fmt.Println("")
	fmt.Println("Structs:")

	v := Vertex{1, 2}
	fmt.Printf("v - Type: %T, Value: %v\n", v, v)

	v2 := Vertex{}
	fmt.Printf("v2 - Type: %T, Value: %v\n", v2, v2)
	v2.Y = 100
	fmt.Printf("v2 - Type: %T, Value: %v\n", v2, v2)

	v3 := Vertex{X: 10}
	fmt.Printf("v3 - Type: %T, Value: %v\n", v3, v3)

	pv := &v3
	pv.Y = 9999
	fmt.Printf("pv - Type: %T, Value: %v\n", pv, pv)
	fmt.Printf("*pv - Type: %T, Value: %v\n", *pv, *pv)

	fmt.Println("")
	fmt.Println("Arrays:")

	var str_list [2]string
	str_list[0] = "Hello"
	str_list[1] = "World"
	fmt.Printf("str_list: Type=%T, Value=%#v, len=%v, cap=%v\n", str_list, str_list, len(str_list), cap(str_list))
	fmt.Printf("str_list[0] - Type: %T, Value: %#v, len=%v\n", str_list[0], str_list[0], len(str_list[0]))
	fmt.Printf("strings.Join(): %s\n", strings.Join(str_list[:], "-"))

	{
		lx := [2]int{1, 2}
		ly := [...]int{3, 4}
		fmt.Printf("Type of x=%T, Type of y=%T\n", lx, ly)
	}

	int_list := [6]int{1, 3, 5, 9, 7, 2}
	fmt.Printf("int_list - Type: %T, Value: %#v, len=%v, cap=%v\n", int_list, int_list, len(int_list), cap(int_list))

	fmt.Println("\nSlices:")
	var slice []int = int_list[1:4]
	fmt.Printf("slice - Type: %T, Value: %#v, len=%v, cap=%v\n", slice, slice, len(slice), cap(slice))

	vert_list := []Vertex{{0, 10}, {X: 20}, {Y: 30}}
	fmt.Printf("vert_list - Type: %T, Value: %#v, len=%v, cap=%v\n", vert_list, vert_list, len(vert_list), cap(vert_list))

	list_a := make([]int, 10)
	fmt.Printf("list_a - Type: %T, Value: %#v, len=%v, cap=%v\n", list_a, list_a, len(list_a), cap(list_a))

	var s2 []int
	fmt.Printf("s2 - Type: %T, Value: %#v, len=%v, cap=%v\n", s2, s2, len(s2), cap(s2))

	s2 = append(s2, 99)
	fmt.Printf("s2 - Type: %T, Value: %#v, len=%v, cap=%v\n", s2, s2, len(s2), cap(s2))

	s2 = append(s2, 999, 19990)
	fmt.Printf("s2 - Type: %T, Value: %#v, len=%v, cap=%v\n", s2, s2, len(s2), cap(s2))

	for index, value := range s2 {
		fmt.Printf("range s2: index=%v, value=%v\n", index, value)
	}

	fmt.Println("\nMaps:")

	var a_map map[string]Vertex
	fmt.Printf("a_map - Type: %T, Value: %#v, len=%v\n", a_map, a_map, len(a_map))

	a_map = make(map[string]Vertex)
	fmt.Printf("a_map - Type: %T, Value: %#v, len=%v\n", a_map, a_map, len(a_map))

	a_map["home"] = Vertex{123, 456}
	fmt.Printf("a_map - Type: %T, Value: %#v, len=%v\n", a_map, a_map, len(a_map))

	a_map["office"] = Vertex{3, 9}
	fmt.Printf("a_map - Type: %T, Value: %#v, len=%v\n", a_map, a_map, len(a_map))

	{
		value, found := a_map["work"]
		fmt.Printf("a_map[\"work\"]: value: %v, found: %v\n", value, found)
	}

	{
		value, found := a_map["home"]
		fmt.Printf("a_map[\"home\"]: value: %v, found: %v\n", value, found)
	}

	fmt.Println("\nFunction Values:")
	{
		hypot := func(x, y float64) float64 {
			return math.Sqrt(x*x + y*y)
		}

		fmt.Printf("hypot: Type=%T, Value=%v\n", hypot, hypot)
		fmt.Printf("hypot( 5, 12 ): %v\n", hypot(5, 12))
		fmt.Printf("pass_3_4(hypot): %v\n", pass_3_4(hypot))
		fmt.Printf("pass_3_4((math.Pow): %v\n", pass_3_4(math.Pow))
	}

	fmt.Println("\nFunction closures:")
	{
		pos, neg := adder(), adder()
		for index := 0; index < 5; index++ {
			fmt.Printf("pos(%v): %v\n", index, pos(index))
			fmt.Printf("neg(-2*%v): %v\n", index, neg(-2*index))
		}
	}
}

func pass_3_4(fn func(float64, float64) float64) float64 {
	return fn(3, 4)
}

func adder() func(int) int {
	sum := 0
	return func(x int) int {
		sum += x
		return sum
	}
}
