package game

import (
	"fmt"
	"leaf/serverdemo/core"

	"github.com/name5566/leaf/chanrpc"
	"github.com/name5566/leaf/module"
)

var Skeleton *module.Skeleton

func init() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

	Skeleton = &module.Skeleton{
		GoLen:              10000,
		TimerDispatcherLen: 10000,
		AsynCallLen:        10000,
		ChanRPCServer:      chanrpc.NewServer(10000),
	}

	Skeleton.Init()
	Skeleton.RegisterChanRPC("NewAgent", rpcNewAgent)
	Skeleton.RegisterChanRPC("CloseAgent", rpcCloseAgent)
}

func rpcNewAgent(args []interface{}) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName(), args)
}

func rpcCloseAgent(args []interface{}) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName(), args)
}
