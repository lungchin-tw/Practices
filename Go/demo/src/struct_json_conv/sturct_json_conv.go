package main

import (
	"encoding/json"
	"fmt"
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

func main() {
	container := TestContainer{
		Timestamp: time.Now().Unix(),
		Components: map[string]TestComp{
			"0": TestComp{1, 1, 1},
			"1": TestComp{2, 2, 2},
			"2": TestComp{3, 3, 3},
		},
	}

	fmt.Printf("Container=%#v\n\n", container)

	byte_array, err := json.Marshal(container)
	fmt.Printf("JSONStr=%#v, Error=%v\n\n", string(byte_array), err)

	ctr_from := TestContainer{}
	err = json.Unmarshal(byte_array, &ctr_from)
	fmt.Printf("ContainerAfter=%#v, Error=%v\n", ctr_from, err)
}
