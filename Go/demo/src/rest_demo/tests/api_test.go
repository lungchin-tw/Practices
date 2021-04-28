package api_test

import (
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"testing"
)

func printBody(body io.ReadCloser) {
	defer body.Close()
	payload, err := ioutil.ReadAll(body)
	fmt.Println("Body:", string(payload))
	fmt.Println("Error:", err)
}

func TestIndex(t *testing.T) {
	url := "http://localhost:8080"
	rsp, err := http.Get(url)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("Response From %v: %+v", url, rsp)
	printBody(rsp.Body)
}

func TestHello(t *testing.T) {
	url := "http://localhost:8080/hello/jacky"
	rsp, err := http.Get(url)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("Response From %v: %+v", url, rsp)

	printBody(rsp.Body)
}

func TestAddUser(t *testing.T) {
	url := "http://localhost:8080/user/1000"
	rsp, err := http.Post(url, "", nil)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("Response From %v: %+v", url, rsp)

	printBody(rsp.Body)
}

func TestDelUser(t *testing.T) {
	url := "http://localhost:8080/user/1001"
	req, err := http.NewRequest(http.MethodDelete, url, nil)
	if err != nil {
		t.Fatal(err)
	}

	rsp, err := (&http.Client{}).Do(req)
	t.Logf("Response From %v: %+v", url, rsp)

	printBody(rsp.Body)
}

func TestModifyUser(t *testing.T) {
	url := "http://localhost:8080/user/1002"
	req, err := http.NewRequest(http.MethodPut, url, nil)
	if err != nil {
		t.Fatal(err)
	}

	rsp, err := (&http.Client{}).Do(req)
	t.Logf("Response From %v: %+v", url, rsp)

	printBody(rsp.Body)
}
