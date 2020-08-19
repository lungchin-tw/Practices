package prototest

import (
	"leaf/serverdemo/core"
	"testing"

	"github.com/golang/protobuf/proto"
)

func TestProtoEncodeDecode(t *testing.T) {
	log_cat := core.GetCurFuncName()

	msg := &ProtoExample{
		Label: "ProtoExample",
		Type:  77,
		Reps:  []int64{101, 999},
	}

	encoded, err := proto.Marshal(msg)
	if err != nil {
		t.Fatalf("[%v], %v", log_cat, err)
	}

	t.Logf("[%v], Encoded: %#v", log_cat, encoded)

	decoded := &ProtoExample{}
	err = proto.Unmarshal(encoded, decoded)
	if err != nil {
		t.Fatalf("[%v], %v", log_cat, err)
	}

	t.Logf("[%v], Decoded: %#v", log_cat, decoded)

}
