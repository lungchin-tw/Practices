package game

import (
	"fmt"
	"leaf/serverdemo/core"

	"github.com/name5566/leaf/module"
)

var (
	Module = new(TModule)
)

type TModule struct {
	*module.Skeleton
}

func (this *TModule) OnInit() {
	fmt.Println(core.GetCurFuncName())

	this.Skeleton = Skeleton
}

func (this *TModule) OnDestroy() {
	fmt.Println(core.GetCurFuncName())
}

func (this *TModule) Run(closeSig chan bool) {
	fmt.Println(core.GetCurFuncName(), closeSig)
}
