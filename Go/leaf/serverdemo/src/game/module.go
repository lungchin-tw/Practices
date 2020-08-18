package game

import (
	"fmt"
	"leaf/serverdemo/core"
	"leaf/serverdemo/game/internal"
	"leaf/serverdemo/message"
	"reflect"

	"github.com/name5566/leaf/module"
)

var Module = new(TModule)

type TModule struct {
	*module.Skeleton
}

func (this *TModule) OnInit() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

	this.Skeleton = Skeleton
	message.Processor.SetRouter(&message.HelloMsg{}, Skeleton.ChanRPCServer)
	Skeleton.RegisterChanRPC(reflect.TypeOf(&message.HelloMsg{}), internal.HandleHelloMsg)

	Skeleton.RegisterCommand("echo", "echo user inputs", func(args []interface{}) interface{} {
		return fmt.Sprintf("%v", args)
	})
}

func (this *TModule) OnDestroy() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())
}

func (this *TModule) Run(closeSig chan bool) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName(), closeSig)
	this.Skeleton.Run(closeSig)
}
