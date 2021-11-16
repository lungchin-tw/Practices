package main

import (
	"context"
	"demo/rpc_demo/grpc-demo/pb"

	"fmt"
	"net"

	"google.golang.org/grpc"
)

type ExchangeService struct {
	pb.UnimplementedExchangeServiceServer
}

func (this *ExchangeService) SayHello(ctx context.Context, msg *pb.Message) (*pb.Message, error) {
	fmt.Println(msg.Body)
	return &pb.Message{Body: "Hello, Client"}, nil
}

func main() {
	fmt.Println("Startup Server")

	listener, err := net.Listen("tcp", ":12345")
	if err != nil {
		panic(err)
	}

	server := grpc.NewServer()
	pb.RegisterExchangeServiceServer(server, &ExchangeService{})
	if err := server.Serve(listener); err != nil {
		panic(err)
	}
}
