package main

import (
	"fmt"
	"sync"
	"time"

	progressbar "github.com/schollz/progressbar/v2"
	mpb "github.com/vbauerster/mpb/v4"
	"github.com/vbauerster/mpb/v4/decor"
)

func main() {
	// Single Progress Bar
	{
		bar := progressbar.New(1000)
		for index := 0; index < 10; index++ {
			time.Sleep(100 * time.Millisecond)
			bar.Add(1)
		}
	}

	// Single Progress Bar
	{
		bar := progressbar.NewOptions(100, progressbar.OptionSetRenderBlankState(false))
		for index := 0; index < 100; index++ {
			time.Sleep(100 * time.Millisecond)
			bar.Add(1)
		}
	}

	// Multi Progress Bar
	{
		var wg sync.WaitGroup
		p := mpb.New(mpb.WithWaitGroup(&wg))
		num_bars := 3
		wg.Add(num_bars)

		for index := 0; index < num_bars; index++ {
			name := fmt.Sprintf("Bar#%v", index)
			bar := p.AddBar(100,
				mpb.PrependDecorators(
					decor.Name(name),
					decor.Percentage(decor.WCSyncSpace),
				),
				mpb.AppendDecorators(
					decor.OnComplete(
						decor.EwmaETA(decor.ET_STYLE_GO, 60),
						"DONE",
					),
				),
			)

			go func() {
				defer wg.Done()

			}()
		}
	}

}
