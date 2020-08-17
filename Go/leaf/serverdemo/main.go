package main

import (
	"fmt"
	"leaf/serverdemo/core"
	"leaf/serverdemo/game"
	"leaf/serverdemo/gate"

	"github.com/name5566/leaf"
)

func main() {
	fmt.Println(core.GetCurFile(), core.GetCurFuncName())

	leaf.Run(
		game.Module,
		gate.Module,
	)
}
