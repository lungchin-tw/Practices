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
	this.Skeleton = Skeleton

	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

	message.Processor.SetRouter(&message.HelloMsg{}, Skeleton.ChanRPCServer)

	var m interface{} = &message.HelloMsg{}
	var h interface{} = internal.HandleHelloMsg
	Skeleton.RegisterChanRPC(reflect.TypeOf(m), h)
}

func (this *TModule) OnDestroy() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())
}

func (this *TModule) Run(closeSig chan bool) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName(), closeSig)
	this.Skeleton.Run(closeSig)
}
