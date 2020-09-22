package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"time"

	"demo.gin/protobuf/env"
	"demo.gin/protobuf/pb"
	"talent.com/server/mch-durotar.git/tools/aes"

	"github.com/gin-gonic/gin"
	"github.com/golang/protobuf/proto"
)

func main() {
	router := gin.Default()
	router.POST("/login", func(c *gin.Context) {
		payload, err := ioutil.ReadAll(c.Request.Body)
		if err != nil {
			panic(err)
		}

		payload, err = aes.EcbDecrypt(payload, env.CipherKey)
		if err != nil {
			panic(err)
		}

		decoded := &pb.LoginRequest{}
		if err = proto.Unmarshal(payload, decoded); err != nil {
			panic(err)
		}

		fmt.Printf("Request={%+v}\n", decoded)
		c.ProtoBuf(http.StatusOK, &pb.PingPong{
			Timestamp: time.Now().UnixNano(),
			UserID:    decoded.UserID,
			Token:     decoded.Token,
		})
	})

	router.Run()
}
