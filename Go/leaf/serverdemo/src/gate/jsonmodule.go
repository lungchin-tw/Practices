package gate

import (
	"fmt"
	"leaf/serverdemo/conf"
	"leaf/serverdemo/core"
	"leaf/serverdemo/game"
	"leaf/serverdemo/message"

	"github.com/name5566/leaf/gate"
)

var JsonModule = new(TJsonModule)

type TJsonModule struct {
	*gate.Gate
}

func (this *TJsonModule) OnInit() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

	this.Gate = &gate.Gate{
		MaxConnNum:      conf.MAX_CONN_NUM,
		PendingWriteNum: conf.PENDING_WRITE_NUM,
		MaxMsgLen:       conf.MAX_MSG_LEN,
		WSAddr:          conf.JSON_WSADDR,
		HTTPTimeout:     conf.HTTP_TIMEOUT,
		CertFile:        "",
		KeyFile:         "",
		TCPAddr:         conf.JSON_TCPADDR,
		LenMsgLen:       conf.LEN_MSG_LEN,
		LittleEndian:    conf.IS_LITTLE_ENDIAN,
		Processor:       message.JsonProcessor,
		AgentChanRPC:    game.Skeleton.ChanRPCServer,
	}
}

func (this *TJsonModule) OnDestroy() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())
	this.Gate.OnDestroy()
}

func (this *TJsonModule) Run(closeSig chan bool) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName(), closeSig)
	this.Gate.Run(closeSig)
}
