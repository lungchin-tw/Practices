package internal

import (
	"fmt"
	"leaf/serverdemo/core"
)

func HandleHelloMsg(args []interface{}) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName(), args)
}
