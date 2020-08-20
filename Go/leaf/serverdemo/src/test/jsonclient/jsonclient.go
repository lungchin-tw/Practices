package main

import (
	"encoding/binary"
	"leaf/serverdemo/conf"
	"net"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:7777")
	if err != nil {
		panic(err)
	}

	data := []byte(
		`{
			"HelloJsonMsg": {
				"Name": "test client"
			}
		}`,
	)

	msg := make([]byte, (len(data) + conf.LEN_MSG_LEN))

	if conf.IS_LITTLE_ENDIAN == false {
		binary.BigEndian.PutUint16(msg, uint16(len(data)))
	}

	copy(msg[2:], data)

	conn.Write(msg)
}
