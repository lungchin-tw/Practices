package main

import (
	"encoding/binary"
	"fmt"
	"leaf/serverdemo/conf"
	"leaf/serverdemo/message"
	"net"
	"time"

	"github.com/golang/protobuf/proto"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:7799")
	if err != nil {
		panic(err)
	}

	temp := &message.HelloProtoMsg{
		Name: "Proto Client",
	}

	fmt.Printf("Temp: %#v\n", temp)

	data, err := proto.Marshal(temp)
	if err != nil {
		panic(err)
	} else {
		fmt.Printf("Encoded: %q\n", data)
	}

	id := 0
	id_byte := make([]byte, 2)
	len_byte := make([]byte, 2)
	if conf.IS_LITTLE_ENDIAN == false {
		binary.BigEndian.PutUint16(id_byte, uint16(id))
		binary.BigEndian.PutUint16(len_byte, uint16(len(data)+2))
	} else {
		binary.LittleEndian.PutUint16(id_byte, uint16(id))
		binary.LittleEndian.PutUint16(len_byte, uint16(len(data)+2))
	}

	msg := make([]byte, (len(data) + conf.LEN_MSG_LEN + 2))

	copy(msg[0:], len_byte)
	copy(msg[2:], id_byte)
	copy(msg[4:], data)

	conn.Write(msg)
	time.Sleep(time.Second)

	decoded := &message.HelloProtoMsg{}
	err = proto.Unmarshal(msg[4:], decoded)
	if err != nil {
		panic(err)
	} else {
		fmt.Printf("Decoded: %#v\n", decoded)
	}
}
