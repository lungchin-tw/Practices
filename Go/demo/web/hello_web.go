package main

import (
	"fmt"
	"net/http"
	"time"
)

func greet(w http.ResponseWriter, r *http.Request) {
	context := fmt.Sprintf("Hello World! %s", time.Now())
	fmt.Println(context)
	fmt.Fprintln(w, context)
}

func main() {
	http.HandleFunc("/greet", greet)
	http.ListenAndServe(":8080", nil)
}
