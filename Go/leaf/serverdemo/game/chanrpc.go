package game

import (
	"fmt"
	"leaf/serverdemo/core"

	"github.com/name5566/leaf/chanrpc"
	"github.com/name5566/leaf/module"
)

var (
	Skeleton = newSkeleton()
)

func newSkeleton() *module.Skeleton {
	fmt.Println(core.GetCurFuncName())

	instance := &module.Skeleton{
		GoLen:              10000,
		TimerDispatcherLen: 10000,
		AsynCallLen:        10000,
		ChanRPCServer:      chanrpc.NewServer(10000),
	}

	instance.Init()
	return instance
}
