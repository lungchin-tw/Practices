package main

import (
	"fmt"
)

const (
	EGET_NONE = -1 + iota
	EGET_INVALID_STAGE
	EGET_INVALID_ACTION
	EGET_INVALID_TYPE
	EGET_ACTION_ALREADY
	EGET_PLAYER_EXISTS
	EGET_SCENE_IS_FULL
)

func main() {
	fmt.Println(EGET_NONE)
	fmt.Println(EGET_INVALID_STAGE)
	fmt.Println(EGET_INVALID_ACTION)
	fmt.Println(EGET_INVALID_TYPE)
	fmt.Println(EGET_ACTION_ALREADY)

}
