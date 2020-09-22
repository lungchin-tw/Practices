package main

import (
	"bytes"
	"fmt"
	"io/ioutil"
	"math/rand"
	"net/http"
	"time"

	"demo.gin/protobuf/env"
	"demo.gin/protobuf/pb"

	"github.com/golang/protobuf/proto"
	"github.com/google/uuid"

	"talent.com/server/mch-durotar.git/tools/aes"
)

func main() {

	rand.Seed(time.Now().UnixNano())
	data := &pb.LoginRequest{
		Timestamp: time.Now().UnixNano(),
		UserID:    rand.Uint64(),
		Token:     uuid.New().String(),
		MerCode:   "test",
	}

	// data := &pb.PingPong{
	// 	Timestamp: time.Now().UnixNano(),
	// 	UserID:    rand.Uint64(),
	// 	Token:     uuid.New().String(),
	// }

	payload, err := proto.Marshal(data)
	if err != nil {
		panic(err)
	}

	if *env.UseCipher == true {
		payload = aes.EcbEncrypt(payload, env.CipherKey)
	}

	resp, err := http.Post("http://localhost:8080/login", "", bytes.NewBuffer(payload))
	fmt.Printf("Response=%+v, Error=%v\n", resp, err)

	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		panic(err)
	}

	decoded := &pb.PingPong{}
	if err = proto.Unmarshal(body, decoded); err != nil {
		panic(err)
	}

	fmt.Printf("Decoded={%+v}\n", decoded)
}
