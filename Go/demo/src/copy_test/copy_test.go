package copy_test

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
