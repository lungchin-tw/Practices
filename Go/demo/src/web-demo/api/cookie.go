package api

import (
	"examples/web-demo/utils"
	"fmt"
	"net/http"
	"strings"
	"time"
)

func HandleCookie(w http.ResponseWriter, r *http.Request) {
	fmt.Println("handleCookie, Cookies:", r.Cookies())
	if err := r.ParseForm(); err != nil {
		utils.ProcessRequestException(err, w, r)
		return
	}

	username := r.URL.Path[len("/cookie/"):]
	if len(username) < 1 {
		w.WriteHeader(http.StatusBadRequest)
		fmt.Fprintln(w, "username not found")
		return
	}

	expiry := time.Now().Add(time.Minute * 10)
	http.SetCookie(w, &http.Cookie{
		Name:     "user",
		Value:    username,
		HttpOnly: true,
		Expires:  expiry,
	})

	fmt.Fprintln(w, "Cookies:", r.Cookies())
	fmt.Fprintln(w, "Method:", r.Method)
	fmt.Fprintln(w, "URL:", r.URL)
	fmt.Fprintln(w, "Form:", r.Form)
	for k, v := range r.Form {
		fmt.Fprintln(w, "Key:", k)
		fmt.Fprintln(w, "Value:", strings.Join(v, ","))
	}
}
