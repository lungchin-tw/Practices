package main

import "fmt"

func main() {
	a := [...]int{1, 2, 3, 4, 5, 6}
	fmt.Printf("a=%#v\n", a)

	s := a[1:4]
	fmt.Printf("s=%#v, len=%v, cap=%v\n", s, len(s), cap(s))

	s = append(s, 10, 11, 12, 13)
	fmt.Printf("s=%#v, len=%v, cap=%v\n", s, len(s), cap(s))
	fmt.Printf("a=%#v\n", a)

	s = s[1:4]
	fmt.Printf("s=%#v, len=%v, cap=%v\n", s, len(s), cap(s))

}
