package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	resp, err := http.Get("http://localhost:8080/ping")
	fmt.Printf("Response=%+v, Error=%+v\n", resp, err)

	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	fmt.Printf("Body=%s, Error=%+v\n", body, err)
}
