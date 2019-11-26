package main

import (
	"fmt"
	"os"
	"path/filepath"
)

func main() {
	path, err := os.Getwd()
	fmt.Printf("os.Getwd()=%v, %v\n", path, err)

	fmt.Printf("os.Args=%#v\n", os.Args)
	dir := filepath.Dir(os.Args[0])
	fmt.Printf("Dir=%v\n", dir)

	path, err = filepath.Abs(dir)
	fmt.Printf("Abs(Dir)=%v, %+v\n", path, err)

	path, err = filepath.Abs(filepath.Join(dir, "../../"))
	fmt.Printf("filepath.Abs(filepath.Join(Dir, \"../../\"))=%v, %+v\n", path, err)
}
