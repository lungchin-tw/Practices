package main

import (
	"time"

	progressbar "github.com/schollz/progressbar/v2"
)

func main() {
	{
		bar := progressbar.New(1000)
		for index := 0; index < 10; index++ {
			time.Sleep(100 * time.Millisecond)
			bar.Add(1)
		}
	}

	{
		bar := progressbar.NewOptions(100, progressbar.OptionSetRenderBlankState(false))
		for index := 0; index < 100; index++ {
			time.Sleep(100 * time.Millisecond)
			bar.Add(1)
		}
	}

}
