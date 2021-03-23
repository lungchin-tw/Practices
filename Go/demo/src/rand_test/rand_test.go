package main

import (
	"encoding/base64"
	"math/rand"
	"testing"
)

func TestRandRead(t *testing.T) {
	b := make([]byte, 32)
	rand.Read(b)
	t.Log("rand.Read(b):", b)
	t.Log("URLEncoding:", base64.URLEncoding.EncodeToString(b))
}
