package utils

import (
	"fmt"
	"runtime"
)

func curFrame(skip int) runtime.Frame {
	pc := make([]uintptr, 1)
	num := runtime.Callers(skip, pc)
	if num <= 0 {
		return runtime.Frame{}
	}

	frame, _ := runtime.CallersFrames(pc).Next()
	return frame
}

func CurFuncName() string {
	return curFrame(3).Function
}

func CurLine() int {
	return curFrame(3).Line
}

func CurLineDesc() string {
	frame := curFrame(3)
	return fmt.Sprintf("%v:%v", frame.Function, frame.Line)
}

func GetCurFile() string {
	return curFrame(3).File
}
