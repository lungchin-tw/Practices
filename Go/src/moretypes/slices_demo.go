package main

import (
	"fmt"
)

func main() {
	fmt.Println("Arrays:")

	int_list := [6]int{1, 3, 5, 9, 7, 2}
	fmt.Printf("int_list - Type: %T, Value: %#v, len=%v, cap=%v\n", int_list, int_list, len(int_list), cap(int_list))

	var slice []int = int_list[1:4]
	fmt.Printf("slice - Type: %T, Value: %#v, len=%v, cap=%v\n", slice, slice, len(slice), cap(slice))

	slice = append(slice, 99)
	fmt.Printf("slice - Type: %T, Value: %#v, len=%v, cap=%v\n", slice, slice, len(slice), cap(slice))

	slice = append(slice, 999)
	fmt.Printf("slice - Type: %T, Value: %#v, len=%v, cap=%v\n", slice, slice, len(slice), cap(slice))

	slice = append(slice, 999)
	fmt.Printf("slice - Type: %T, Value: %#v, len=%v, cap=%v\n", slice, slice, len(slice), cap(slice))

	fmt.Printf("int_list - Type: %T, Value: %#v, len=%v, cap=%v\n", int_list, int_list, len(int_list), cap(int_list))

	fmt.Println("\n2DSlice:")
	board := [][]int{
		[]int{1, 2, 3},
		make([]int, 3),
		[]int{7, 8, 9},
	}
	fmt.Printf("board - Type: %T, Value: %#v, len=%v, cap=%v\n", board, board, len(board), cap(board))

	board_2 := make([][]int, 3)
	fmt.Printf("board_2 - Type: %T, Value: %#v, len=%v, cap=%v\n", board_2, board_2, len(board_2), cap(board_2))

}
