package main

import (
	"fmt"
	"reflect"
)

func getLength(in interface{}) int {
	return reflect.ValueOf(in).Len()
}

type SubGame struct {
	subGameName string
}

type Game struct {
	GameID   int
	GameName string
	players  []uint64
	subGame  SubGame
}

func main() {
	{
		slice := make([]int, 10)
		v := reflect.ValueOf(slice)
		fmt.Println("Kind:", v.Kind())
		fmt.Println("Len:", v.Len())
		// fmt.Println("Len of [0]:", reflect.ValueOf(slice[0]).Len())
	}

	fmt.Println("")

	{
		array := [2]int{}
		v := reflect.ValueOf(array)
		fmt.Println("Kind:", v.Kind())
		fmt.Println("Len:", v.Len())
	}

	fmt.Println("")

	{
		t := reflect.TypeOf(Game{})
		fmt.Printf("reflect.TypeOf(Game{}): %#v\n", t)
		fmt.Println("t.Align():", t.Align())
		fmt.Println("t.FieldAlign():", t.FieldAlign())
		fmt.Println("t.NumMethod():", t.NumMethod())
		fmt.Println("t.Name():", t.Name())
		fmt.Println("t.PkgPath():", t.PkgPath())
		fmt.Println("t.PkgPath():", t.PkgPath())
		fmt.Println("t.String():", t.String())
		fmt.Println("t.Kind():", t.Kind())
		fmt.Println("t.Comparable():", t.Comparable())
		// fmt.Println("t.Bits():", t.Bits())
		// fmt.Println("t.ChanDir():", t.ChanDir())
		// fmt.Println("t.IsVariadic():", t.IsVariadic())
		// fmt.Println("t.Elem():", t.Elem())
		// fmt.Println("t.Key():", t.Key())
		// fmt.Println("t.Len():", t.Len())
		fmt.Println("t.NumField():", t.NumField())
		// fmt.Println("t.NumIn():", t.NumIn())
		// fmt.Println("t.NumOut():", t.NumOut())
		for i := 0; i < t.NumField(); i++ {
			field := t.FieldByIndex([]int{i})
			fmt.Printf("Field[%v], Kind:%v\n", i, field.Type.Kind())
			if field.Type.Kind() == reflect.Struct {
				field = t.FieldByIndex([]int{i, 0})
				fmt.Printf("Field[%v], %#v\n", []int{i, 0}, field)
			} else {
				fmt.Printf("Field[%v], %#v\n", i, field)
			}

		}
	}
}
