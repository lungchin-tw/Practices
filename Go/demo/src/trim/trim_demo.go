package main

import "strings"

import "fmt"

func main() {
	str := " x y z "
	fmt.Printf("strings.TrimSpace(%v) = (%v)\n", str, strings.TrimSpace(str))
	fmt.Printf("strings.Trim(%v, \"\\t \"\\n\") = (%v)\n", str, strings.Trim(str, "\t \n"))
}
