package api

import (
	"fmt"
	"html/template"
	"net/http"
	"strings"
)

func HandleXSS(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	if r.Method == "GET" {
		t, _ := template.ParseFiles("template/xss.gtpl")
		t.Execute(w, nil)
	} else {
		r.ParseForm()
		fmt.Println("username:", template.HTMLEscapeString(r.Form.Get("username"))) // print at server side
		fmt.Println("password:", template.HTMLEscapeString(r.Form.Get("password")))
		fmt.Fprintln(w, template.HTMLEscapeString(r.Form.Get("username"))) // responded to clients
		fmt.Fprintln(w, template.HTMLEscapeString(r.Form.Get("password"))) // responded to clients
	}

	for k, v := range r.Form {
		fmt.Fprintln(w, "Key:", template.HTMLEscapeString(k))
		fmt.Fprintln(w, "Value:", template.HTMLEscapeString(strings.Join(v, ",")))
	}
	fmt.Fprintln(w, "HandleXSS") // send data to client side
}

func WithoutHandleXSS(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	if r.Method == "GET" {
		t, _ := template.ParseFiles("template/woxss.gtpl")

		// simulate that client sent invalid context.
		// t.Execute(w, "some-page.com/no-image.jpg\" onerror=\"alert(\"Hacked!!\")\"")
		t.Execute(w, nil)
	} else {
		r.ParseForm()
		fmt.Println("username:", r.Form.Get("username")) // print at server side
		fmt.Println("password:", r.Form.Get("password"))
		fmt.Fprintln(w, r.Form.Get("username")) // responded to clients
		fmt.Fprintln(w, r.Form.Get("password")) // responded to clients
	}

	for k, v := range r.Form {
		fmt.Fprintln(w, "Key:", k)
		fmt.Fprintln(w, "Value:", strings.Join(v, ","))
	}
	fmt.Fprintln(w, "WithoutHandleXSS") // send data to client side
}
