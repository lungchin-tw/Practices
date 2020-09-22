package aes_test

import (
	"encoding/base64"
	"fmt"
	"math/rand"
	"testing"
	"time"

	"demo.gin/protobuf/env"
	"demo.gin/protobuf/pb"
	"github.com/google/uuid"
	"google.golang.org/protobuf/proto"
	"talent.com/server/mch-durotar.git/tools/aes"
)

func TestMain(m *testing.M) {
	rand.Seed(time.Now().UnixNano())
	env.InitValues()
	m.Run()
}

func TestEncryption(t *testing.T) {
	before := &pb.LoginRequest{
		Timestamp: time.Now().UnixNano(),
		UserID:    rand.Uint64(),
		Token:     uuid.New().String(),
		MerCode:   "test",
	}

	payload, err := proto.Marshal(before)
	if err != nil {
		panic(err)
	} else {
		fmt.Printf("[TestEncryption], Before={%+v}\n", before)
	}

	encoded := aes.EcbEncrypt(payload, env.CipherKey)
	decoded, err := aes.EcbDecrypt(encoded, env.CipherKey)
	if err != nil {
		panic(nil)
	}

	var after = &pb.LoginRequest{}
	if err = proto.Unmarshal(decoded, after); err != nil {
		panic(err)
	} else {
		fmt.Printf("[TestEncryption], After={%+v}\n", after)
	}
}

func TestCipherGenerator(t *testing.T) {
	bytes := make([]byte, 16)
	if _, err := rand.Read(bytes); err != nil {
		panic(err)
	}

	ciphervalue := base64.StdEncoding.EncodeToString(bytes)
	fmt.Println("CipherValue,", ciphervalue)

	if cipherkey, err := base64.StdEncoding.DecodeString(string(ciphervalue)); err != nil {
		panic(nil)
	} else {
		fmt.Println("CipherKey,", cipherkey)
	}
}
