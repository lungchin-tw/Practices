package message

import (
	"fmt"
	"leaf/serverdemo/core"

	"github.com/name5566/leaf/network/json"
	"github.com/name5566/leaf/network/protobuf"
)

var JsonProcessor = json.NewProcessor()
var ProtoProcessor = protobuf.NewProcessor()

func init() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())
}
