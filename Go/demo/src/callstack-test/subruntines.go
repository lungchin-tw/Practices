package test

import (
	"fmt"
	"runtime"
)

func DoLayer1() {
	fmt.Println("DoLayer1")

	DoLayer2()
}

func DoLayer2() {
	fmt.Println("DoLayer2")

	DoTrace()
}

func DoTrace() {
	fmt.Println("DoTrace")

	pc := make([]uintptr, 10)
	num := runtime.Callers(0, pc)
	fmt.Println("runtime.Callers(0,pc):", num)
	fmt.Printf("pc:%#v\n", pc)
	// log.Panic()

	frames := runtime.CallersFrames(pc[:num])
	for {
		frame, more := frames.Next()
		// fmt.Printf("More=%v, Frame: %+v\n", more, frame)
		fmt.Printf("%v\n\t%v:%v\n", frame.Function, frame.File, frame.Line)
		if more == false {
			break
		}
	}

}
