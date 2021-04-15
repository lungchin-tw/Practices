package main

import (
	"flag"
	"net"
	"testing"
)

var Addr = flag.String("addr", "localhost:1234", "host addr")

func buildClientConn(addr string) *net.TCPConn {
	tcpaddr, err := net.ResolveTCPAddr("tcp", *Addr)
	checkError(err)

	conn, err := net.DialTCP("tcp", nil, tcpaddr)
	checkError(err)
	return conn
}

func TestTcpClientCase01(t *testing.T) {
	flag.Parse()

	conn := buildClientConn(*Addr)
	_, err := conn.Write([]byte("HEAD / HTTP/1.0\r\n\r\n"))
	checkError(err)

	var response [1024]byte
	numread, err := conn.Read(response[0:])
	checkError(err)
	t.Log("Response:", string(response[:numread]))
}

func TestTcpClientCase02(t *testing.T) {
	flag.Parse()

	conn := buildClientConn(*Addr)
	_, err := conn.Write([]byte("timestamp"))
	checkError(err)

	var response [1024]byte
	numread, err := conn.Read(response[0:])
	checkError(err)
	t.Log("Response:", string(response[:numread]))
}
