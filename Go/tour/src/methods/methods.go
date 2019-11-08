package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type Vertex struct {
	X, Y float64
}

func (value Vertex) Abs() float64 {
	return math.Sqrt(value.X*value.X + value.Y*value.Y)
}

func (value *Vertex) Random() *Vertex {
	if value == nil {
		fmt.Println("func (value *Vertex) Random() *Vertex: value == nil")
		return value
	}

	rand.Seed(time.Now().UTC().UnixNano())
	value.X = rand.Float64()
	value.Y = rand.Float64()
	return value
}

type TFloat float64

func (value TFloat) Abs() float64 {
	if value < 0 {
		return float64(-value)
	}

	return float64(value)
}

type Abser interface {
	Abs() float64
}

type RandGenerator interface {
	Random() *Vertex
}

type MF struct {
}

func (value MF) String() string {
	return fmt.Sprintf("Mother Fucker ~~~")
}

func main() {
	v := Vertex{X: 3, Y: 4}
	fmt.Printf("v=%+v\n", v)
	fmt.Printf("v.Abs(): %v\n", v.Abs())

	f := TFloat(-math.Sqrt2)
	fmt.Printf("-math.Sqrt2: %v\n", -math.Sqrt2)
	fmt.Printf("TFloat(-math.Sqrt2).Abs(): %v\n", f.Abs())

	v.Random()
	fmt.Printf("v.Random()=%+v\n", v)

	fmt.Println("\nInterfaces:")

	var abser Abser
	// abser.Abs() abser is nil, this will raise an exception
	fmt.Printf("abser: Type=%T, Value=%v\n", abser, abser)

	abser = v
	fmt.Printf("abser=v: Type=%T, Value=%+v, abser.Abs()=%v\n", abser, abser, abser.Abs())

	abser = &v
	fmt.Printf("abser=&v: Type=%T, Value=%+v, abser.Abs()=%v\n", abser, abser, abser.Abs())

	abser = f
	fmt.Printf("abser=f: Type=%T, Value=%v, abser.Abs()=%v\n", abser, abser, abser.Abs())

	abser = &f
	fmt.Printf("abser=&f: Type=%T, Value=%v, abser.Abs()=%v\n", abser, abser, abser.Abs())

	var nil_vert_ptr *Vertex
	var rg RandGenerator = nil_vert_ptr
	fmt.Printf("rg=nil_vert_ptr: Type=%T, Value=%v, rg.Random()=%v\n", rg, rg, rg.Random())

	var empty_intf interface{}
	fmt.Printf("empty_intf: Type=%T, Value=%v\n", empty_intf, empty_intf)

	empty_intf = 40
	fmt.Printf("empty_intf: Type=%T, Value=%v\n", empty_intf, empty_intf)

	empty_intf = "Hello, world"
	fmt.Printf("empty_intf: Type=%T, Value=%v\n", empty_intf, empty_intf)

	fmt.Println("\nType assertions:")

	s := empty_intf.(string)
	fmt.Printf("s: Type=%T, Value=%v\n", s, s)

	int_value, ok := empty_intf.(int)
	fmt.Printf("int_value: Type=%T, Value=%v, ok=%v\n", int_value, int_value, ok)

	fmt.Println("\nType switches:")
	var nil_intf Abser
	demoTypeSwitches(nil_intf)
	demoTypeSwitches(v)
	demoTypeSwitches(f)
	demoTypeSwitches(abser)
	demoTypeSwitches(empty_intf)
	demoTypeSwitches(rg)
	demoTypeSwitches(s)
	demoTypeSwitches(int_value)
	demoTypeSwitches(ok)

	fmt.Println("\nStringers:")
	fmt.Printf("MF{}: %v", MF{})

	// int_value = empty_intf.(int) this will raise a exception
}

func demoTypeSwitches(value interface{}) {
	if value == nil {
		fmt.Println("demoTypeSwitches: value == nil")
	}

	switch value.(type) {
	case bool:
		fmt.Printf("demoTypeSwitches: value.(type)=bool, Value=%v\n", value)
	case int:
		fmt.Printf("demoTypeSwitches: value.(type)=int, Value=%v\n", value)
	case string:
		fmt.Printf("demoTypeSwitches: value.(type)=string, Value=%v\n", value)
	case float64:
		fmt.Printf("demoTypeSwitches: value.(type)=float64, Value=%v\n", value)
	case Vertex:
		fmt.Printf("demoTypeSwitches: value.(type)=Vertex, Value=%v\n", value)
	default:
		fmt.Printf("demoTypeSwitches: value.(type)=Unknown, Type=%T, Value=%v\n", value, value)
	}
}
