package main

import (
	"leaf/serverdemo/game"
	"leaf/serverdemo/gate"

	"github.com/name5566/leaf"
)

func main() {
	leaf.Run(
		game.Module,
		gate.Module,
	)
}
