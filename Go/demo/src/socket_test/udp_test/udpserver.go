package main

import (
	"flag"
	"fmt"
	"net"
	"strconv"
	"time"
)

var Port = flag.Int("port", 1234, "Listening Port")

func main() {
	flag.Parse()

	udpaddr, err := net.ResolveUDPAddr("udp4", fmt.Sprintf(":%v", *Port))
	checkError(err)

	conn, err := net.ListenUDP("udp", udpaddr)
	checkError(err)

	fmt.Println("[net.ListenUDP], New Connection:", conn.RemoteAddr(), conn.LocalAddr())
	for {
		handleUDPConnection(conn)
	}
}

func handleUDPConnection(conn *net.UDPConn) {
	payload := make([]byte, 1024)
	numread, udpaddr, err := conn.ReadFromUDP(payload)
	if err != nil {
		fmt.Println("[handleConnection], Error:", err)
		return
	}

	fmt.Println("[handleConnection], UDPAddr:", udpaddr)
	fmt.Println("[handleConnection], Payload:", string(payload[:numread]))

	response := make([]byte, 1024)
	if string(payload[:numread]) == "timestamp" {
		response = []byte(strconv.FormatInt(time.Now().Unix(), 10))
	} else {
		response = []byte(time.Now().String())
	}

	conn.WriteToUDP(response, udpaddr)
	fmt.Println("[handleConnection], Write:", string(response))
}
