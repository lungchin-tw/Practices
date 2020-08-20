package message

import (
	"fmt"
	"leaf/serverdemo/conf"
	"leaf/serverdemo/core"
	"reflect"

	"github.com/name5566/leaf/network/json"
	"github.com/name5566/leaf/network/protobuf"
)

var JsonProcessor = json.NewProcessor()
var ProtoProcessor = protobuf.NewProcessor()

func init() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())
	JsonProcessor.Register(&HelloJsonMsg{})

	ProtoProcessor.SetByteOrder(conf.IS_LITTLE_ENDIAN)
	ProtoProcessor.Register(&HelloProtoMsg{})
	ProtoProcessor.Range(func(id uint16, t reflect.Type) {
		fmt.Println(core.GetCurFile(), core.GetCurFuncName(), id, t)
	})
}
