package apitests

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"net/http/cookiejar"
	"testing"

	"golang.org/x/net/publicsuffix"
)

func TestCookie(t *testing.T) {
	const url = "http://localhost:8080/cookie/apitests"

	fmt.Println("## Request ###")

	req, err := http.NewRequest(http.MethodGet, url, nil)
	if err != nil {
		t.Fatal(err)
	}

	jar, err := cookiejar.New(&cookiejar.Options{PublicSuffixList: publicsuffix.List})
	if err != nil {
		t.Fatal(err)
	}

	fmt.Println("jar.Cookies():", jar.Cookies(req.URL))
	fmt.Println("req.Cookies():", req.Cookies())
	fmt.Println("## Response ###")
	resp, err := (&http.Client{Jar: jar}).Do(req)
	if err != nil {
		t.Fatal(err)
		return
	}

	fmt.Println("resp.ContentLength:", resp.ContentLength)
	fmt.Println("resp.Cookies:", resp.Cookies())
	fmt.Println("jar:", jar)

	defer resp.Body.Close()
	payload, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		t.Fatal(err)
		return
	}

	fmt.Println("Payload:")
	fmt.Println(string(payload))
}
