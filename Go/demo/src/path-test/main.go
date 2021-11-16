package main

import (
	"fmt"
	"os"
	"path/filepath"
)

func main() {
	file_path := GetCurFile()
	fmt.Println("Frame.File:", file_path)
	fmt.Println("Base:", filepath.Base(file_path))
	fmt.Println("Clean:", filepath.Clean(file_path))
	fmt.Println("FromSlash:", filepath.FromSlash(file_path))

	path, err := os.Getwd()
	fmt.Printf("os.Getwd()=%v, %v\n", path, err)
	fmt.Printf("os.Args=%#v\n", os.Args)
}
