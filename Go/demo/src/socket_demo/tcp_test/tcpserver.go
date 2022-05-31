package main

import (
	"flag"
	"fmt"
	"net"
	"strconv"
	"strings"
	"time"
)

var Port = flag.Int("port", 1234, "Listening Port")

func main() {
	flag.Parse()

	tcpaddr, err := net.ResolveTCPAddr("tcp", fmt.Sprintf(":%v", *Port))
	checkError(err)
	fmt.Printf("TCPAddr:%v, Error:%v\n", tcpaddr, err)

	listener, err := net.ListenTCP("tcp", tcpaddr)
	checkError(err)

	for {
		if conn, err := listener.Accept(); err != nil {
			fmt.Println("[listener.Accept], Error:", err)
		} else {
			fmt.Println("[listener.Accept], New Connection:", conn.RemoteAddr(), conn.LocalAddr())
			go handleConnection(conn)
		}
	}
}

func handleConnection(conn net.Conn) {
	conn.SetReadDeadline(time.Now().Add(time.Minute))
	defer conn.Close()

	var readbuffer [1024]byte
	for {
		numread, err := conn.Read(readbuffer[0:])
		if err != nil {
			fmt.Println("[handleConnection], Error:", err)
			break
		} else if numread == 0 {
			fmt.Println("[handleConnection], Connection Closed By Client")
			break
		}

		payload := readbuffer[:numread]
		payloadstr := strings.TrimRight(string(payload), "\n")
		fmt.Printf("Payload: %v", payload)
		if payloadstr == "timestamp" {
			fmt.Println("[handleConnection], Timestamp")
			daytime := strconv.FormatInt(time.Now().Unix(), 10)
			conn.Write([]byte(daytime))
			fmt.Println("[handleConnection], Write:", daytime)
		} else {
			fmt.Println("[handleConnection], Payload:", payloadstr)
			response := fmt.Sprintf("Payload:%v, Timestamp:%v", payloadstr, time.Now().String())
			conn.Write([]byte(response))
			fmt.Println("[handleConnection], Write:", response)
		}

		conn.Write([]byte{10})
	}
}
