package message

import (
	"fmt"
	"leaf/serverdemo/core"
)

type HelloJsonMsg struct {
	Name string
}

func init() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

}
