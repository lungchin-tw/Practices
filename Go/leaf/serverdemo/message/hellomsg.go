package message

import "github.com/name5566/leaf/network/json"

var Processor = json.NewProcessor()

type HelloMsg struct {
	Name string
}
