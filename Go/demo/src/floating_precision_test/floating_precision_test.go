package floating_precision_test

import (
	"testing"
)

func TestFloatingPrcision(t *testing.T) {
	f := 1.0
	for f < 2.0 {
		t.Logf("Float: %v, Int: %v", f, int64(f))
		f += 0.1
	}
}
