package main

import "strings"

import "fmt"

func main() {
	str := " x y z "
	fmt.Printf("strings.TrimSpace(%v) = (%v)\n", str, strings.TrimSpace(str))
	fmt.Printf("strings.Trim(%v, \"\\t \"\\n\") = (%v)\n", str, strings.Trim(str, "\t \n"))

	{
		filename := "123.456"
		index := strings.LastIndex(filename, ".")
		fmt.Printf("strings.LastIndex(%v, \".\"): %v\n", filename, index)
		slice := filename[:index]
		fmt.Println("slice:", slice)
	}

	{
		ext := ".docx"
		if ext[0] == '.' {
			ext = ext[1:]
		}

		fmt.Println("ext:", ext)

		if ext[0] != '.' {
			ext = "." + ext
		}

		fmt.Println("ext:", ext)
	}
}
