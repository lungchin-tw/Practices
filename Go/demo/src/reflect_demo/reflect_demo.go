package main

import (
	"fmt"
	"reflect"
)

func getLength(in interface{}) int {
	return reflect.ValueOf(in).Len()
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
}
