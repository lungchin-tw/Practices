package main

import (
	"demo/rpc_demo/arith"
	"fmt"
	"log"
	"net/http"
	"net/rpc"
)

func main() {
	fmt.Println("Startup HTTP RPC Server.")
	rpc.Register(new(arith.Arith))
	rpc.HandleHTTP()

	log.Fatal(http.ListenAndServe(":12345", nil))
}
