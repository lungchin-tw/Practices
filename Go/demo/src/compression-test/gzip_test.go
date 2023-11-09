package compressiontest

import (
	"bytes"
	"compress/gzip"
	"math"
	"math/rand"
	"testing"
)

func TestLandGridCompression(t *testing.T) {
	const length = 1024
	const area = length * length
	grid := make([]byte, area)

	for k := range grid {
		/*
		* a large different compression rate between these 2 kind of data arrangement.
		 */
		grid[k] = byte(rand.Intn(math.MaxUint8))
		// grid[k] = byte(k % math.MaxUint8)
	}

	t.Logf("Before: %v", len(grid))

	var buf bytes.Buffer
	buf.Reset()
	gw := gzip.NewWriter(&buf)
	defer gw.Close()

	if n, err := gw.Write(grid); err != nil {
		t.Fatal(err)
	} else {
		t.Logf("N: %v", n)
	}

	gw.Flush()
	after := len(buf.Bytes())

	t.Logf("After: %v", after)
	t.Logf("Compression Rate: %.4f", float64(100)*(float64(1)-(float64(after)/float64(area))))
}
