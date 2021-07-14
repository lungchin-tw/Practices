package main

import (
	"examples/web-demo/api"
	"examples/web-demo/i18n"
	_ "examples/web-demo/session"
	"examples/web-demo/utils"
	"fmt"
	"math/rand"
	"net/http"
	"os"
	"time"
)

func sayhelloName(w http.ResponseWriter, r *http.Request) {
	r.ParseForm() // parse arguments, you have to call this by yourself
	utils.WriteReq(w, r)
	fmt.Fprintln(w, "URLLong:", r.Form["url_long"])
	fmt.Fprintln(w, "URLLong:", r.FormValue("url_long"))
	fmt.Fprintln(w, "Hello astaxie!") // send data to client side
}

func handleUser(w http.ResponseWriter, r *http.Request) {
	r.ParseForm() // parse arguments, you have to call this by yourself
	utils.WriteReq(w, r)
	fmt.Fprintln(w, "ID:", r.URL.Path[len("/user/"):])
	fmt.Fprintln(w, "handleUser") // send data to client side
}

func redirect(w http.ResponseWriter, r *http.Request) {
	http.Redirect(w, r, "https://www.google.com", http.StatusMovedPermanently)
}

func main() {
	rand.Seed(time.Now().UnixNano())

	panicerr := make(chan error)
	path, _ := os.Getwd()
	fmt.Println(path)
	http.HandleFunc("/sayhelloName", sayhelloName)
	http.HandleFunc("/user/", handleUser)
	http.HandleFunc("/redirect", redirect)
	http.HandleFunc("/login", api.HandleLogin)
	http.HandleFunc("/xss", api.HandleXSS)
	http.HandleFunc("/woxss", api.WithoutHandleXSS)
	http.HandleFunc("/upload", api.HandleUpload)
	http.HandleFunc("/cookie/", api.HandleCookie)
	http.HandleFunc("/count", api.HandleCount)
	http.HandleFunc("/i18n/", i18n.HandleI18N)
	go func() {
		if err := http.ListenAndServe(":8080", nil); err != nil {
			panicerr <- err
		}
	}()

	fmt.Println("Web Server Startup.")
	panic(<-panicerr)
}
