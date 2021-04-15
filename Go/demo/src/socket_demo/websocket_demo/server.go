package main

import (
	"flag"
	"fmt"
	"net/http"

	"golang.org/x/net/websocket"
)

var Port = flag.Int("port", 1234, "Listening Port")

func main() {
	flag.Parse()

	http.Handle("/", websocket.Handler(func(ws *websocket.Conn) {
		fmt.Println("Handle Web Socket Request")
		for {
			var payload string
			if err := websocket.Message.Receive(ws, &payload); err != nil {
				fmt.Println(err)
				break
			}

			fmt.Println("Received:", payload)
			if err := websocket.Message.Send(ws, payload); err != nil {
				fmt.Println(err)
				break
			}
		}
	}))

	addr := fmt.Sprintf(":%v", *Port)
	fmt.Println("http.ListenAndServe", addr)
	if err := http.ListenAndServe(addr, nil); err != nil {
		panic(err)
	}
}
