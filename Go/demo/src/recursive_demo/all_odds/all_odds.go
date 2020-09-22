package main

import "fmt"

func MultiplyIntArray(list []int) int {
	sum := 1
	for _, value := range list {
		sum *= value
	}

	return sum
}

func Calculator(
	list []int,
	curdepth int,
	maxdepth int,
	p []int,
	permutations map[int]int,
) {
	if curdepth >= maxdepth {
		permutations[MultiplyIntArray(p)] = 1
		return
	} else {
		for _, value := range list {
			Calculator(list, (curdepth + 1), maxdepth, append(p, value), permutations)
		}
	}
}

func main() {
	var ODDS = []int{1, 2, 3, 5}
	var Permutations map[int]int

	const MAX_DEPTH = 5
	/*
	** Iterative Method
	 */
	// Permutations = make(map[int]int)
	// for _, value_0 := range ODDS {
	// 	for _, value_1 := range ODDS {
	// 		for _, value_2 := range ODDS {
	// 			for _, value_3 := range ODDS {
	// 				for _, value_4 := range ODDS {
	// 					Permutations[value_0*value_1*value_2*value_3*value_4] = 1
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	// fmt.Printf("\nIterative Method\n")
	// fmt.Println("Permutations Len=", len(Permutations))
	// fmt.Println("Permutations=", Permutations)

	/*
	** Recursive Method
	 */
	for startdepth := 1; startdepth <= MAX_DEPTH; startdepth++ {
		Permutations = make(map[int]int)

		Calculator(
			ODDS,
			0,
			startdepth,
			[]int{},
			Permutations,
		)

		fmt.Printf("\nRecursive Method, MaxDepth=%v:\n", startdepth)
		fmt.Println("Permutations Len=", len(Permutations))
		fmt.Println("Permutations=", Permutations)
	}

	Permutations = make(map[int]int)
	for startdepth := 1; startdepth <= MAX_DEPTH; startdepth++ {
		Calculator(
			ODDS,
			0,
			startdepth,
			[]int{},
			Permutations,
		)
	}

	fmt.Printf("\nRecursive Method, All Permutations:\n")
	fmt.Println("Permutations Len=", len(Permutations))
	fmt.Println("Permutations=", Permutations)
}
