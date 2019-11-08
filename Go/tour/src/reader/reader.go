package main

import (
	"fmt"
	"io"
	"strings"
)

func main() {
	r := strings.NewReader("Mother Fucker, Reader!!(我問天~~我問天~~)")
	b := make([]byte, 8)

	for {
		n, err := r.Read(b)
		fmt.Printf("n=%v, err=%v, b=%v\n", n, err, b)
		fmt.Printf("b[:%v] = %q\n", n, b[:n])
		if err == io.EOF {
			fmt.Println("err == io.EOF")
			break
		}
	}
}
