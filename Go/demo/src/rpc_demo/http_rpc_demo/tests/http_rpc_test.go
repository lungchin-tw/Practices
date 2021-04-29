package tests

import (
	"net/rpc"
	"testing"
)

type Args struct {
	A, B int
}

type Quotient struct {
	Quo, Rem int
}

func dial() (*rpc.Client, error) {
	const addr = "localhost:12345"
	return rpc.DialHTTP("tcp", addr)
}

func TestHTTP_RPC_Multiply(t *testing.T) {
	client, err := dial()
	if err != nil {
		t.Fatal(err)
	}

	defer client.Close()

	args := Args{A: 7, B: 3}
	method := "Arith.Multiply"
	var reply int
	if err := client.Call(method, args, &reply); err != nil {
		t.Fatal(err)
	}

	t.Logf("%v, Args: %v, Reply: %v", method, args, reply)
}

func TestHTTP_RPC_DivideCase01(t *testing.T) {
	client, err := dial()
	if err != nil {
		t.Fatal(err)
	}

	defer client.Close()

	args := Args{A: 7, B: 0}
	method := "Arith.Divide"
	var reply Quotient
	if err := client.Call(method, args, &reply); err != nil {
		t.Log(err)
	} else {
		t.Fatalf("[%v], Args:%v Must be Fatal!", method, args)
	}
}

func TestHTTP_RPC_DivideCase02(t *testing.T) {
	client, err := dial()
	if err != nil {
		t.Fatal(err)
	}

	defer client.Close()

	args := Args{A: 7, B: 3}
	method := "Arith.Divide"
	var reply Quotient
	if err := client.Call(method, args, &reply); err != nil {
		t.Fatal(err)
	}

	t.Logf("%v, Args: %v, Reply: %v", method, args, reply)
}
