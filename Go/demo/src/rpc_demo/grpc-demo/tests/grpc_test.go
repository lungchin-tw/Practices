package tests

import (
	"context"
	"examples/rpc_demo/grpc-demo/pb"
	"testing"
	"time"

	"google.golang.org/grpc"
)

const address = "localhost:12345"

func TestGRPC_SayHello(t *testing.T) {
	ctx, cancel := context.WithTimeout(context.Background(), time.Second*3)
	defer cancel()

	conn, err := grpc.DialContext(ctx, address, grpc.WithInsecure(), grpc.WithBlock())
	if err != nil {
		t.Fatal("Dial...", address, err)
	}

	defer conn.Close()

	client := pb.NewExchangeServiceClient(conn)

	t.Log("Got Context With Timeout.")

	msg, err := client.SayHello(ctx, &pb.Message{Body: "A Greeting From Client."})
	t.Logf("Message:%v, Error:%v", msg, err)
}
