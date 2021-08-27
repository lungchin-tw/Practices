package main

import (
	"testing"
	"time"
)

func TestSelect02(t *testing.T) {
	tick := time.Tick(time.Second)
	boom := time.Tick(time.Second * 3)

	for {
		select {
		case <-boom:
			t.Log("BOOM!!!")
			return

		default:
			t.Log("Tick,", <-tick)
		}
	}
}
