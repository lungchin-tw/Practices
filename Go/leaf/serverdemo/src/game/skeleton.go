package game

import (
	"fmt"
	"leaf/serverdemo/core"

	"github.com/name5566/leaf/chanrpc"
	"github.com/name5566/leaf/gate"
	"github.com/name5566/leaf/module"
)

var Skeleton *module.Skeleton

func init() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

	chanrpcserver := chanrpc.NewServer(10000)
	Skeleton = &module.Skeleton{
		GoLen:              10000,
		TimerDispatcherLen: 10000,
		AsynCallLen:        10000,
		ChanRPCServer:      chanrpcserver,
	}

	Skeleton.Init()

	/*
		Method 1:
		Skeleton.RegisterChanRPC("NewAgent", rpcNewAgent)
		Skeleton.RegisterChanRPC("CloseAgent", rpcCloseAgent)
	*/

	// Method 2:
	chanrpcserver.Register("NewAgent", rpcNewAgent)
	chanrpcserver.Register("CloseAgent", rpcCloseAgent)
}

func rpcNewAgent(args []interface{}) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName(), args)

	agent := args[0].(gate.Agent)
	fmt.Printf(`
		New Agent: %#v
		Agent.LocalAddr: %q
		Agent.RemoteAddr: %q`+"\n",
		agent, agent.LocalAddr(), agent.RemoteAddr(),
	)
}

func rpcCloseAgent(args []interface{}) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName(), args)

	agent := args[0].(gate.Agent)
	fmt.Printf(`
		New Agent: %#v
		Agent.LocalAddr: %q
		Agent.RemoteAddr: %q`+"\n",
		agent, agent.LocalAddr(), agent.RemoteAddr())
}
