package api_test

import (
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"testing"
)

const PORT = 8080

func ENDPOINT() string {
	return "demo.jacky.tw"
	// return "192.168.1.206"
}

func init() {
	fmt.Println("End Point", ENDPOINT())
	fmt.Println("Port:", PORT)
}

func printBody(body io.ReadCloser) {
	defer body.Close()
	payload, err := ioutil.ReadAll(body)
	fmt.Println("Body:", string(payload))
	fmt.Println("Error:", err)
}

func TestIndex(t *testing.T) {
	url := fmt.Sprintf("http://%v:%v", ENDPOINT(), PORT)
	rsp, err := http.Get(url)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("Response From %v: %+v", url, rsp)
	printBody(rsp.Body)
}

func TestHello(t *testing.T) {
	url := fmt.Sprintf("http://%v:%v/hello/jacky", ENDPOINT(), PORT)
	rsp, err := http.Get(url)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("Response From %v: %+v", url, rsp)

	printBody(rsp.Body)
}

func TestAddUser(t *testing.T) {
	url := fmt.Sprintf("http://%v:%v/user/1000", ENDPOINT(), PORT)
	rsp, err := http.Post(url, "", nil)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("Response From %v: %+v", url, rsp)

	printBody(rsp.Body)
}

func TestDelUser(t *testing.T) {
	url := fmt.Sprintf("http://%v:%v/user/1001", ENDPOINT(), PORT)
	req, err := http.NewRequest(http.MethodDelete, url, nil)
	if err != nil {
		t.Fatal(err)
	}

	rsp, err := (&http.Client{}).Do(req)
	t.Logf("Response From %v: %+v", url, rsp)

	printBody(rsp.Body)
}

func TestModifyUser(t *testing.T) {
	url := fmt.Sprintf("http://%v:%v/user/1002", ENDPOINT(), PORT)
	req, err := http.NewRequest(http.MethodPut, url, nil)
	if err != nil {
		t.Fatal(err)
	}

	rsp, err := (&http.Client{}).Do(req)
	t.Logf("Response From %v: %+v", url, rsp)

	printBody(rsp.Body)
}
