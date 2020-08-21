package internal

import (
	"fmt"
	"leaf/serverdemo/core"
	"leaf/serverdemo/message"

	"github.com/name5566/leaf/gate"
)

func HandleHelloJsonMsg(args []interface{}) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

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

func HandleHelloProtoMsg(args []interface{}) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())
	msg := args[0].(*message.HelloProtoMsg)
	agent := args[1].(gate.Agent)

	fmt.Printf(
		"File: %v\nFunc: %v\nArgs: %#v\nMessage: %#v\nRemoteAddr: %q\n",
		core.GetCurFile(),
		core.GetCurFuncName(),
		args,
		*msg,
		agent.RemoteAddr(),
	)

	agent.WriteMsg(
		&message.HelloProtoMsg{
			Name: "serverdemo",
		},
	)
}
