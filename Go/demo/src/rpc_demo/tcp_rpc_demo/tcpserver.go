package main

import (
	"examples/rpc_demo/arith"
	"fmt"
	"net"
	"net/rpc"
)

func main() {
	fmt.Println("Startup TCP RPC Server.")
	rpc.Register(new(arith.Arith))

	tcpaddr, err := net.ResolveTCPAddr("tcp", ":12345")
	if err != nil {
		panic(err)
	}

	listener, err := net.ListenTCP("tcp", tcpaddr)
	if err != nil {
		panic(err)
	}

	for {
		if conn, err := listener.Accept(); err == nil {
			rpc.ServeConn(conn)
		} else {
			fmt.Println(err)
		}
	}
}
