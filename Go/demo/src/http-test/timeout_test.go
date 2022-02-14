package http_test

import (
	"encoding/json"
	"io"
	"net/http"
	"net/http/httptest"
	"testing"
	"time"
)

func TestClientTimeout(t *testing.T) {
	const Timeout = 20 * time.Millisecond
	handler := http.HandlerFunc(func(rw http.ResponseWriter, r *http.Request) {
		t.Log("HandlerFunc")
		time.Sleep(Timeout * 2)
		bytes, err := json.Marshal(map[string]interface{}{
			"id":    "12",
			"scope": "test-scope",
		})

		if err != nil {
			t.Error(err)
		}

		io.WriteString(rw, string(bytes))
		rw.WriteHeader(http.StatusOK)
	})

	server := httptest.NewServer(http.TimeoutHandler(handler, Timeout, "server timeout"))
	t.Log("Server Started.", server.URL)
	defer server.Close()

	rsp, err := http.DefaultClient.Get(server.URL)
	if err != nil {
		t.Error(err)
		return
	}

	t.Log("Response Status:", rsp.Status)
	if rsp.StatusCode == http.StatusOK {
		t.FailNow()
	}

	t.Log("Response:", rsp)
}
