package main

import (
	"fmt"

	"github.com/aws/aws-lambda-go/lambda"
)

type DemoRequest struct {
	Action string `json:"action"`
	Data   string `json:"data"`
}

type DemoResponse struct {
	StatusCode    int    `json:"statusCode"`
	StatusMessage string `json:"statusMessage"`
}

func handler(req DemoRequest) (DemoResponse, error) {
	info := fmt.Sprintf("Request:%#v", req)
	fmt.Println(info)
	return DemoResponse{StatusCode: 200, StatusMessage: fmt.Sprintf("OK, %v", info)}, nil
}

func main() {
	lambda.Start(handler)
}
