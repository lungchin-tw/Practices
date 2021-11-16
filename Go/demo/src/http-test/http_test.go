package http_test

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"net/http/httptest"
	"testing"
)

func TestHTTPTest(t *testing.T) {
	server := httptest.NewServer(http.HandlerFunc(func(rw http.ResponseWriter, r *http.Request) {
		t.Log("HandlerFunc")
		fmt.Fprintln(rw, "Greeting~~")
	}))

	t.Log("Server Started.", server.URL)
	defer server.Close()

	t.Log("New Request GET", server.URL)
	res, err := http.Get(server.URL)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("Response: %v, Error:%v", res, err)

	payload, err := ioutil.ReadAll(res.Body)
	if err != nil {
		t.Fatal(err)
	}

	t.Log("Payload:", string(payload))
}
