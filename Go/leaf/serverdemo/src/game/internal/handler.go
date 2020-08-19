package internal

import (
	"fmt"
	"leaf/serverdemo/core"
	"leaf/serverdemo/message"

	"github.com/name5566/leaf/gate"
)

func HandleHelloJsonMsg(args []interface{}) {
	msg := args[0].(*message.HelloJsonMsg)
	agent := args[1].(gate.Agent)

	fmt.Printf(
		"File=%v\nFunc=%v\nArgs=%+v\nMessage=%+v\nAgent=%+v\n",
		core.GetCurFile(),
		core.GetCurFuncName(),
		args,
		*msg,
		agent,
	)

	agent.WriteMsg(
		&message.HelloJsonMsg{
			Name: "serverdemo",
		},
	)
}
