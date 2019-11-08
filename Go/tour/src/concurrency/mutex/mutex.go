package main

import (
	"fmt"
	"sync"
	"time"
)

type SaveCounter struct {
	value map[string]int
	mutex sync.Mutex
}

func (inst *SaveCounter) Inc(key string) {
	inst.mutex.Lock()
	inst.value[key]++
	fmt.Println("inst.value[key] =", inst.value[key])
	inst.mutex.Unlock()
}

func (inst *SaveCounter) Value(key string) int {
	inst.mutex.Lock()
	defer inst.mutex.Unlock()
	return inst.value[key]
}

func main() {
	inst := SaveCounter{value: make(map[string]int)}
	for index := 0; index < 1000; index++ {
		go inst.Inc("demo")
	}

	time.Sleep(time.Second)
	fmt.Println("Num of \"demo\": ", inst.Value("demo"))
}
