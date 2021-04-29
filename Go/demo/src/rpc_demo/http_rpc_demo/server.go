package main

import (
	"fmt"
	"log"
	"net/http"
	"net/rpc"
)

type Args struct {
	A, B int
}

type Quotient struct {
	Quo, Rem int
}

type Arith int

func (this *Arith) Multiply(args *Args, reply *int) error {
	fmt.Println("Arith.Multiply", args)
	*reply = args.A * args.B
	return nil
}

func (this *Arith) Divide(args *Args, reply *Quotient) error {
	fmt.Println("Arith.Divide", args)
	if args.B == 0 {
		return fmt.Errorf("[Arith.Divide], Invalid Args:%v", args)
	}

	reply.Quo = args.A / args.B
	reply.Rem = args.A % args.B
	return nil
}

func main() {
	fmt.Println("Startup Server.")
	rpc.Register(new(Arith))
	rpc.HandleHTTP()

	log.Fatal(http.ListenAndServe(":12345", nil))
}
