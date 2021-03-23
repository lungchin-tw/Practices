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
		t, _ := template.ParseFiles("xss.gtpl")
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
	fmt.Fprintln(w, "handleXSS") // send data to client side
}
