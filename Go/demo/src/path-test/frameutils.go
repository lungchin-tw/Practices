package main

import (
	"fmt"
	"runtime"
)

func GetCurFrame(skip int) runtime.Frame {
	pc := make([]uintptr, 1)
	num := runtime.Callers(skip, pc)
	if num <= 0 {
		return runtime.Frame{}
	}

	frame, _ := runtime.CallersFrames(pc).Next()
	return frame
}

func GetCurFuncName() string {
	return GetCurFrame(3).Function
}

func GetCurLine() int {
	return GetCurFrame(3).Line
}

func GetCurFuncNameLine() (string, int) {
	frame := GetCurFrame(3)
	return frame.Function, frame.Line
}

func GetCurFile() string {
	return GetCurFrame(3).File
}

func LogFunc() string {
	frame := GetCurFrame(3)
	return fmt.Sprintf("[%v:%v]", frame.Function, frame.Line)
}
