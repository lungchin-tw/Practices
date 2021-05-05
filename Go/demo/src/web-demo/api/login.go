package api

import (
	"examples/web-demo/utils"
	"fmt"
	"html/template"
	"net/http"
)

func HandleLogin(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	if r.Method == "GET" {
		t, err := template.ParseFiles("template/login.gtpl")
		if err != nil {
			utils.WriteReq(w, r)
			fmt.Fprintln(w, template.HTMLEscapeString(err.Error()))
			return
		}

		t.Execute(w, utils.GenToken())
	} else {
		r.ParseForm()
		fmt.Fprintln(w, "username:", template.HTMLEscapeString(r.Form.Get("username")))
		fmt.Fprintln(w, "password:", template.HTMLEscapeString(r.Form.Get("password")))
		fmt.Fprintln(w, "token:", template.HTMLEscapeString(r.Form.Get("token")))
		// http.Redirect(w, r, "/", http.StatusFound)
	}

	utils.WriteReq(w, r)
	fmt.Fprintln(w, "handleLogin") // send data to client side
}
