package main

import (
	"crypto/md5"
	"fmt"
	"html/template"
	"io"
	"net/http"
	"strconv"
	"strings"
	"time"
)

func processRequestException(err error, w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	w.WriteHeader(http.StatusBadRequest)
	writeReq(w, r)
	fmt.Fprintln(w, "Error:", template.HTMLEscapeString(err.Error()))
}

func writeReq(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Request: %#v\n", r)
	fmt.Fprintf(w, "URL: %#v\n", r.URL)
	fmt.Fprintln(w, "Method:", r.Method)
	fmt.Fprintln(w, "Form:", r.Form)
	for k, v := range r.Form {
		fmt.Fprintln(w, "Key:", k)
		fmt.Fprintln(w, "Value:", strings.Join(v, ","))
	}
}

func genToken() string {
	curtime := time.Now().UnixNano()
	h := md5.New()
	io.WriteString(h, strconv.FormatInt(curtime, 10))
	token := fmt.Sprintf("%x", h.Sum(nil))
	fmt.Println("CurrentTime:", curtime)
	fmt.Println("CurrentTime(md5):", h.Sum(nil))
	fmt.Println("CurrentTime(md5):", string(h.Sum(nil)))
	fmt.Println("CurrentTime(md5):", token)
	return token
}
