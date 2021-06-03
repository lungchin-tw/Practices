package test

import (
	"runtime"
	"testing"
)

func CurFrame(skip int) runtime.Frame {
	pc := make([]uintptr, 1)
	num := runtime.Callers(skip, pc)
	if num <= 0 {
		return runtime.Frame{}
	}

	frame, _ := runtime.CallersFrames(pc).Next()
	return frame
}

func TestCallStackCase01(t *testing.T) {
	DoNestCallStackCase01(t)
	// return fmt.Sprintf("%v:%v", frame.Function, frame.Line)
	// DoLayer1()
}

func DoNestCallStackCase01(t *testing.T) {
	DoNestNestCallStackCase01(t)
}

func DoNestNestCallStackCase01(t *testing.T) {
	frame := CurFrame(4)
	t.Logf("%v:%v", frame.Function, frame.Line)
}
