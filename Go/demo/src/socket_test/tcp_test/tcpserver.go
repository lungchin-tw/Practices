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

	payload := make([]byte, 1024)
	for {
		if numread, err := conn.Read(payload); err != nil {
			fmt.Println("[handleConnection], Error:", err)
			break
		} else if numread == 0 {
			fmt.Println("[handleConnection], Connection Closed By Client")
			break
		} else if string(payload[:numread]) == "timestamp" {
			fmt.Println("[handleConnection], Timestamp")
			daytime := strconv.FormatInt(time.Now().Unix(), 10)
			conn.Write([]byte(daytime))
			fmt.Println("[handleConnection], Write:", daytime)
		} else {
			fmt.Println("[handleConnection], Payload:", string(payload[:numread]))
			daytime := time.Now().String()
			conn.Write([]byte(daytime))
			fmt.Println("[handleConnection], Write:", daytime)
		}
	}
}
