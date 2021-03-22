package main

import (
	"fmt"
	"math/rand"
	"net/http"
	"os"
	"time"
	_ "web/session"
)

func sayhelloName(w http.ResponseWriter, r *http.Request) {
	r.ParseForm() // parse arguments, you have to call this by yourself
	writeReq(w, r)
	fmt.Fprintln(w, "URLLong:", r.Form["url_long"])
	fmt.Fprintln(w, "URLLong:", r.FormValue("url_long"))
	fmt.Fprintln(w, "Hello astaxie!") // send data to client side
}

func handleUser(w http.ResponseWriter, r *http.Request) {
	r.ParseForm() // parse arguments, you have to call this by yourself
	writeReq(w, r)
	fmt.Fprintln(w, "ID:", r.URL.Path[len("/user/"):])
	fmt.Fprintln(w, "handleUser") // send data to client side
}

func main() {
	rand.Seed(time.Now().UnixNano())

	panicerr := make(chan error)
	path, _ := os.Getwd()
	fmt.Println(path)
	http.HandleFunc("/sayhelloName", sayhelloName)
	http.HandleFunc("/user/", handleUser)
	http.HandleFunc("/login", handleLogin)
	http.HandleFunc("/xss", handleXSS)
	http.HandleFunc("/upload", handleUpload)
	http.HandleFunc("/cookie/", handleCookie)
	go func() {
		if err := http.ListenAndServe(":8080", nil); err != nil {
			panicerr <- err
		}
	}()

	fmt.Println("Web Server Startup.")
	panic(<-panicerr)
}
