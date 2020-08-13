package gate

import (
	"fmt"
	"leaf/serverdemo/core"
	"leaf/serverdemo/message"

	"time"

	"leaf/serverdemo/game"

	"github.com/name5566/leaf/gate"
)

var (
	Module = new(TModule)
)

type TModule struct {
	*gate.Gate
}

func (this *TModule) OnInit() {
	fmt.Println(core.GetCurFuncName())

	this.Gate = &gate.Gate{
		MaxConnNum:      20000,
		PendingWriteNum: 2000,
		MaxMsgLen:       4096,
		WSAddr:          "0.0.0.0:6666",
		HTTPTimeout:     10 * time.Second,
		TCPAddr:         "0.0.0.0:7777",
		LenMsgLen:       2,
		LittleEndian:    false,
		Processor:       message.Processor,
		AgentChanRPC:    game.Skeleton.ChanRPCServer,
	}
}

func (this *TModule) OnDestroy() {
	fmt.Println(core.GetCurFuncName())
}

func (this *TModule) Run(closeSig chan bool) {
	fmt.Println(core.GetCurFuncName(), closeSig)
}
