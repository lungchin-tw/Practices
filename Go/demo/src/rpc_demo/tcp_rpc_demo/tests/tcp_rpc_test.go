package tests

import (
	"examples/rpc_demo/arith"
	"net/rpc"
	"testing"
)

func tcpdial() (*rpc.Client, error) {
	const addr = "localhost:12345"
	return rpc.Dial("tcp", addr)
}

func TestTCP_RPC_Multiply(t *testing.T) {
	client, err := tcpdial()
	if err != nil {
		t.Fatal(err)
	}

	defer client.Close()

	args := arith.Args{A: 7, B: 3}
	method := "Arith.Multiply"
	var reply int
	if err := client.Call(method, args, &reply); err != nil {
		t.Fatal(err)
	}

	t.Logf("%v, Args: %v, Reply: %v", method, args, reply)
}

func TestTCP_RPC_DivideCase01(t *testing.T) {
	client, err := tcpdial()
	if err != nil {
		t.Fatal(err)
	}

	defer client.Close()

	args := arith.Args{A: 7, B: 0}
	method := "Arith.Divide"
	var reply arith.Quotient
	if err := client.Call(method, args, &reply); err != nil {
		t.Log(err)
	} else {
		t.Fatalf("[%v], Args:%v Must be Fatal!", method, args)
	}
}

func TestTCP_RPC_DivideCase02(t *testing.T) {
	client, err := tcpdial()
	if err != nil {
		t.Fatal(err)
	}

	defer client.Close()

	args := arith.Args{A: 7, B: 3}
	method := "Arith.Divide"
	var reply arith.Quotient
	if err := client.Call(method, args, &reply); err != nil {
		t.Fatal(err)
	}

	t.Logf("%v, Args: %v, Reply: %v", method, args, reply)
}
