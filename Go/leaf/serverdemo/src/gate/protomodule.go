package gate

import (
	"fmt"
	"leaf/serverdemo/conf"
	"leaf/serverdemo/core"
	"leaf/serverdemo/game"
	"leaf/serverdemo/message"

	"github.com/name5566/leaf/gate"
)

var ProtoModule = new(TProtoModule)

type TProtoModule struct {
	*gate.Gate
}

func (this *TProtoModule) OnInit() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

	this.Gate = &gate.Gate{
		MaxConnNum:      conf.MAX_CONN_NUM,
		PendingWriteNum: conf.PENDING_WRITE_NUM,
		MaxMsgLen:       conf.MAX_MSG_LEN,
		WSAddr:          conf.PROTO_WSADDR,
		HTTPTimeout:     conf.HTTP_TIMEOUT,
		CertFile:        "",
		KeyFile:         "",
		TCPAddr:         conf.PROTO_TCPADDR,
		LenMsgLen:       conf.LEN_MSG_LEN,
		LittleEndian:    conf.IS_LITTLE_ENDIAN,
		Processor:       message.ProtoProcessor,
		AgentChanRPC:    game.Skeleton.ChanRPCServer,
	}
}

func (this *TProtoModule) OnDestroy() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())
	this.Gate.OnDestroy()
}

func (this *TProtoModule) Run(closeSig chan bool) {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName(), closeSig)
	this.Gate.Run(closeSig)
}
