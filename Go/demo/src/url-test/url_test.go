package test

import (
	"encoding/json"
	"net/url"
	"testing"
)

func TestURLParse(t *testing.T) {
	const rawurl = "http://localhost:8080/cookie?user=apitests&token=123"
	result, _ := url.Parse(rawurl)
	bytes, _ := json.MarshalIndent(result, "", "")
	t.Log(string(bytes))
	t.Log("url.QueryEscape:", url.QueryEscape(result.RawQuery))
}

func TestURLParseChinese(t *testing.T) {
	const rawurl = "http://localhost:8080/cookie/客戶端?user=陳龍進&token=123"
	result, _ := url.Parse(rawurl)
	t.Log("EscapedPath:", result.EscapedPath())
	t.Log("Hostname:", result.Hostname())
	mb, err := result.MarshalBinary()
	t.Log("MarshalBinary:", string(mb), err)
	t.Log("Query:", result.Query())
	t.Log("RequestURI:", result.RequestURI())
	t.Log("String:", result.String())

	bytes, _ := json.MarshalIndent(result, "", "")
	t.Log(string(bytes))
	query := url.QueryEscape(result.RawQuery)
	t.Log("url.QueryEscape:", query)
	query, err = url.QueryUnescape(query)
	t.Log("url.QueryUnescape:", query, err)
}
