package main

import (
	"fmt"
)

const (
	EGET_NONE = -1 + iota
	EGET_INVALID_STAGE
	EGET_INVALID_ACTION
	EGET_INVALID_TYPE
	EGET_ACTION_ALREADY
	EGET_PLAYER_EXISTS
	EGET_SCENE_IS_FULL
)

func randByWeightArray(weight_array []int, total_weight int, selected int) int {
	sum := 0
	for index, weight := range weight_array {
		if (selected >= sum) && (selected < (sum + weight)) {
			return index
		} else {
			sum += weight
		}
	}

	return -1
}

func main() {
	weights := []int{20, 35, 60, 45, 40}
	sum_weights := 0
	for _, value := range weights {
		sum_weights += value
	}

	fmt.Println("randByWeightArray:", 0, ", Result:", randByWeightArray(weights, sum_weights, 0))
	fmt.Println("randByWeightArray:", (sum_weights - 1), ", Result:", randByWeightArray(weights, sum_weights, (sum_weights-1)))

	numbers := []int{0, 1}
	index := -1
	fmt.Println("numbers[0]", numbers[0])
	// fmt.Println("numbers[2]", numbers[2])
	fmt.Println("numbers[-1]", numbers[index])

	fmt.Println(EGET_NONE)
	fmt.Println(EGET_INVALID_STAGE)
	fmt.Println(EGET_INVALID_ACTION)
	fmt.Println(EGET_INVALID_TYPE)
	fmt.Println(EGET_ACTION_ALREADY)

}
