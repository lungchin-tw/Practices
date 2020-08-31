package main

import (
	"fmt"
	"net/http"
	"sync"
)

var URLS = [...]string{
	"http://www.golang.org/",
	"http://www.google.com/",
	"http://www.somestupidname.com/",
	"http://www.github.com/",
}

func main() {
	var wg sync.WaitGroup

	for index, url := range URLS {
		wg.Add(1)
		go func(index int, url string) {
			fmt.Printf("\nRequesting Url[%v]: %v\n", index, url)

			defer wg.Done()
			resp, err := http.Get(url)
			fmt.Printf("\nResponse From Url[%v]: %v\n", index, url)
			fmt.Printf("Resp: %+v\n", resp)
			fmt.Println("Err:", err)
		}(index, url)
	}

	fmt.Println("\nAll Url's go routines are launched.")

	wg.Wait()
	fmt.Println("\nAll Url's go routines are done.")
}
