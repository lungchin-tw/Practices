package main

import (
	"time"

	"github.com/schollz/progressbar"
)

func main() {
	bar := progressbar.New(100)
	for index := 0; index < 100; index++ {
		time.Sleep(100 * time.Millisecond)
		bar.Add(1)
	}
}
