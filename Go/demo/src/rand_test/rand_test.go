package main

import (
	"encoding/base64"
	"encoding/json"
	"math/rand"
	"testing"
	"time"
)

func TestRandRead(t *testing.T) {
	b := make([]byte, 32)
	rand.Read(b)
	t.Log("b: ", b)
	t.Log("b: ", string(b))
	t.Log("URLEncoding:", base64.URLEncoding.EncodeToString(b))

	str := base64.StdEncoding.EncodeToString(b)
	t.Log("StdEncoding:", str)
	bytes, _ := base64.StdEncoding.DecodeString(str)
	t.Log("StdDecode:", bytes)

	data := struct {
		Bytes []byte
	}{
		Bytes: bytes,
	}

	m, _ := json.MarshalIndent(data, "", "")
	t.Log("Json:", string(m))
}

func TestRandPerm(t *testing.T) {
	rand.Seed(time.Now().UnixMicro())
	t.Log("rand.Perm:", rand.Perm(10))
}

func BenchmarkRandByTimestamp(b *testing.B) {
	for i := 1; i <= b.N; i++ {
		seed := time.Now().UnixMilli()
		_ = seed % int64(i)
	}
}

func BenchmarkRandByDefaultRand(b *testing.B) {
	rand.Seed(time.Now().UnixMicro())
	for i := 1; i <= b.N; i++ {
		_ = rand.Intn(i)
	}
}
