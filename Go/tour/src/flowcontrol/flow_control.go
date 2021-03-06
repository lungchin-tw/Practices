package main

import (
	"fmt"
	"math"
	"runtime"
)

func sqrt(x float64) string {
	if x < 0 {
		return sqrt(-x) + "i"
	}

	return fmt.Sprint(math.Sqrt(x))
}

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	} else {
		fmt.Printf("%g >= %g\n", v, lim)
	}

	return lim
}

func printOS() {
	os_name := "NONE"
	fmt.Printf("runtime.GOOS: %v\n", runtime.GOOS)

	switch runtime.GOOS {
	case "darwin":
		os_name = "macOS"
	case "linux":
		os_name = "Linux"
	case "windows":
		os_name = "Windows"
	}

	fmt.Printf("Go runs on: %v\n", os_name)
}

func main() {
	{
		defer fmt.Println("Test Scoped Defer Statement")
	}

	defer fmt.Println("Test Defer Statement")

	fmt.Println("Common for:")
	sum := 0
	for index := 0; index < 10; index++ {
		sum += index
		fmt.Printf("index: %v, sum: %v\n", index, sum)
		defer fmt.Printf("Test Stacking Defers: %v\n", index)
	}

	// while
	fmt.Println("\nWhile:")
	sum_2 := 1
	for sum_2 < 1000 {
		old_sum := sum_2
		sum_2 += sum_2
		fmt.Printf("sum: %v, sum += sum: %v\n", old_sum, sum_2)
	}

	fmt.Println("\nIf:")
	fmt.Printf("sqrt(2): %#v, sqrt(-4): %#v\n", sqrt(2), sqrt(-4))
	fmt.Println("pow( 3, 2, 10 ): ", pow(3, 2, 10))
	fmt.Println("pow( 3, 3, 20 ): ", pow(3, 3, 20))

	fmt.Println("\nSwitch:")
	printOS()
}
