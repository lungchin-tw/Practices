package message

import (
	"fmt"
	"leaf/serverdemo/core"
)

type HelloMsg struct {
	Name string
}

func init() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())
	Processor.Register(&HelloMsg{})
}
