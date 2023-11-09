package main

import (
	"context"
	"encoding/json"
	"fmt"
	"net/http"

	"github.com/aws/aws-lambda-go/events"
	"github.com/aws/aws-lambda-go/lambda"
)

type RequestContext struct {
	Action string `json:"action"`
	Data   string `json:"data"`
}

func handler(ctx context.Context, req events.APIGatewayProxyRequest) (
	events.APIGatewayProxyResponse,
	error,
) {
	fmt.Printf("req.HTTPMethod: %v\n", req.HTTPMethod)
	fmt.Printf("req.Body: %v\n", req.Body)
	fmt.Printf("req.QueryStringParameters: %v\n", req.QueryStringParameters)
	fmt.Printf("req: %#v\n", req)

	reqctxt := RequestContext{}
	if req.HTTPMethod == http.MethodGet {
		reqctxt.Action = req.QueryStringParameters["action"]
		reqctxt.Data = req.QueryStringParameters["data"]
	} else if req.HTTPMethod == http.MethodPost {
		json.Unmarshal([]byte(req.Body), &reqctxt)
	}

	return events.APIGatewayProxyResponse{
			StatusCode: http.StatusOK,
			Body: fmt.Sprintf(
				"%v, %#v",
				http.StatusText(http.StatusOK), reqctxt),
		},
		nil
}

func main() {
	lambda.Start(handler)
}
