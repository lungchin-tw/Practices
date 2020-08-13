package game

import (
	"fmt"
	"leaf/serverdemo/core"
	"leaf/serverdemo/message"
	"reflect"

	"github.com/name5566/leaf/gate"
)

func init() {
	fmt.Println(core.GetCurFuncName())
	handler(&message.HelloMsg{}, handleHelloMsg)
}

func handler(msg interface{}, handle interface{}) {
	fmt.Println(core.GetCurFuncName(), reflect.TypeOf(msg))
	Skeleton.RegisterChanRPC(reflect.TypeOf(msg), handle)
}

func handleHelloMsg(args []interface{}) {
	msg := args[0].(*message.HelloMsg)
	agent := args[1].(gate.Agent)

	fmt.Println("Hello", msg)
	agent.WriteMsg(&message.HelloMsg{
		Name: "Client",
	})
}
