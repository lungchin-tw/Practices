package test

import (
	"math/rand"
	"testing"
	"time"
)

func TestCopySlice(t *testing.T) {
	rand.Seed(time.Now().UnixNano())

	src := rand.Perm(10)
	t.Log("Src:", src)

	dst := make([]int, len(src))
	copy(dst, src)
	dst[5] = 100
	t.Log("Dst:", dst)
}

type TestData struct {
	A int
}

func TestCopyStructSlice(t *testing.T) {
	rand.Seed(time.Now().UnixNano())

	num := 5 + (rand.Int() % 5)
	origin := make([]TestData, num)
	for i, v := range origin {
		v.A = 10
		t.Log(i, origin[i], v)
	}
}
