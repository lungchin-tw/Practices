package message

import (
	"fmt"
	"leaf/serverdemo/core"

	"github.com/name5566/leaf/network/json"
)

var Processor = json.NewProcessor()

func init() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())
}
