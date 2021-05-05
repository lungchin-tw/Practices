package utils

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

func ProcessRequestException(err error, w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	w.WriteHeader(http.StatusBadRequest)
	WriteReq(w, r)
	fmt.Fprintln(w, "Error:", template.HTMLEscapeString(err.Error()))
}

func WriteReq(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Request: %#v\n", r)
	fmt.Fprintf(w, "URL: %#v\n", r.URL)
	fmt.Fprintln(w, "Method:", r.Method)
	fmt.Fprintln(w, "Form:", r.Form)
	for k, v := range r.Form {
		fmt.Fprintln(w, "Key:", k)
		fmt.Fprintln(w, "Value:", strings.Join(v, ","))
	}
}

func GenToken() string {
	curtime := time.Now().UnixNano()
	fmt.Println("CurrentTime:", curtime)

	h := md5.New()
	fmt.Println("CurrentTime(md5), v0:", h.Sum(nil))

	io.WriteString(h, strconv.FormatInt(curtime, 10))
	fmt.Println("CurrentTime(md5), v1:", h.Sum(nil))

	io.WriteString(h, "hdtxxx")
	fmt.Println("CurrentTime(md5), v2:", h.Sum(nil))
	fmt.Println("CurrentTime(md5), string(v2):", string(h.Sum(nil)))

	token := fmt.Sprintf("%x", h.Sum(nil))
	fmt.Println("token:", token)
	return token
}
