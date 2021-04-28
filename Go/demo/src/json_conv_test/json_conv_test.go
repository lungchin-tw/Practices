package json_conv_test

import (
	"encoding/json"
	"testing"
	"time"
)

type TestComp struct {
	X int `json:"x"`
	Y int `json:"Y"`
	Z int `json:"Z"`
}

type TestContainer struct {
	Timestamp  int64               `json:"Timestamp"`
	Components map[string]TestComp `json:"Components"`
}

func TestJsonConv(t *testing.T) {
	container := TestContainer{
		Timestamp: time.Now().Unix(),
		Components: map[string]TestComp{
			"0": TestComp{1, 1, 1},
			"1": TestComp{2, 2, 2},
			"2": TestComp{3, 3, 3},
		},
	}

	t.Logf("Container: %#v", container)

	byte_array, err := json.Marshal(container)
	t.Logf("JSONStr: %#v, Error: %v", string(byte_array), err)

	ctr_from := TestContainer{}
	err = json.Unmarshal(byte_array, &ctr_from)
	t.Logf("ContainerAfter: %#v, Error: %v", ctr_from, err)
}
