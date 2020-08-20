package main

import (
	"fmt"
	"leaf/serverdemo/conf"
	"leaf/serverdemo/core"
	"leaf/serverdemo/game"
	"leaf/serverdemo/gate"
	"log"

	"github.com/name5566/leaf"
	lconf "github.com/name5566/leaf/conf"
)

func main() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

	lconf.LogLevel = "debug"
	lconf.LogFlag = log.LstdFlags
	lconf.ConsolePort = conf.CONSOLE_PORT

	leaf.Run(
		game.Module,
		// gate.JsonModule,
		gate.ProtoModule,
	)
}
