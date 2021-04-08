package main

import (
	"flag"
	"net"
	"testing"
)

var Addr = flag.String("addr", "localhost:1234", "host addr")

func buildUDPConn(addr string) *net.UDPConn {
	udpaddr, err := net.ResolveUDPAddr("udp", *Addr)
	checkError(err)

	conn, err := net.DialUDP("udp", nil, udpaddr)
	checkError(err)
	return conn
}

func TestUDPClientCase01(t *testing.T) {
	flag.Parse()

	conn := buildUDPConn(*Addr)
	_, err := conn.Write([]byte("HEAD / HTTP/1.0\r\n\r\n"))
	checkError(err)

	response := make([]byte, 1024)
	numread, err := conn.Read(response)
	checkError(err)

	t.Log("Response:", string(response[:numread]))
}

func TestUDPClientCase02(t *testing.T) {
	flag.Parse()

	conn := buildUDPConn(*Addr)
	_, err := conn.Write([]byte("timestamp"))
	checkError(err)

	response := make([]byte, 1024)
	numread, err := conn.Read(response)
	checkError(err)

	t.Log("Response:", string(response[:numread]))
}
