package gate

import (
	"fmt"
	"leaf/serverdemo/core"
	"leaf/serverdemo/game"
	"leaf/serverdemo/message"
)

func init() {
	fmt.Println(core.GetCurFuncName())

	message.Processor.Register(&message.HelloMsg{})
	message.Processor.SetRouter(&message.HelloMsg{}, game.Skeleton.ChanRPCServer)
}
