package main

import (
	"fmt"
	"html/template"
	"net/http"
)

func handleLogin(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	if r.Method == "GET" {
		t, err := template.ParseFiles("login.gtpl")
		if err != nil {
			writeReq(w, r)
			fmt.Fprintln(w, template.HTMLEscapeString(err.Error()))
			return
		}

		t.Execute(w, genToken())
	} else {
		r.ParseForm()
		fmt.Fprintln(w, "username:", template.HTMLEscapeString(r.Form.Get("username")))
		fmt.Fprintln(w, "password:", template.HTMLEscapeString(r.Form.Get("password")))
		fmt.Fprintln(w, "token:", template.HTMLEscapeString(r.Form.Get("token")))
	}

	writeReq(w, r)
	fmt.Fprintln(w, "handleLogin") // send data to client side
}
