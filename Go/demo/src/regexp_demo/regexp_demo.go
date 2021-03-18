package main

import (
	"fmt"
	"regexp"
)

func main() {
	{
		m, err := regexp.MatchString("foo.", "seafood")
		fmt.Println("m, err := regexp.MatchString(\"foo.\", \"seafood\")")
		fmt.Println("Matched:", m, ", Error:", err)
	}

	{
		m, err := regexp.MatchString("^foo", "seafood")
		fmt.Println("m, err := regexp.MatchString(\"^foo\", \"seafood\")")
		fmt.Println("Matched:", m, ", Error:", err)
	}

	{
		m, err := regexp.MatchString("bar.*", "seafood")
		fmt.Println("m, err := regexp.MatchString(\"bar.*\", \"seafood\")")
		fmt.Println("Matched:", m, ", Error:", err)
	}

	{
		m, err := regexp.MatchString("a(b", "seafood")
		fmt.Println("m, err := regexp.MatchString(\"a(b\", \"seafood\")")
		fmt.Println("Matched:", m, ", Error:", err)
	}
}
