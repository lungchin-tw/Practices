package main

import (
	"fmt"
	"sync"
	"time"
)

const NUM = 10

func main() {
	// testNormalMap()
	testSyncMap()
}

func testNormalMap() {
	fmt.Println("testNormalMap")

	var normal_map map[int]string = make(map[int]string)

	for key := 0; key < NUM; key++ {
		go func(key int) {
			fmt.Println("Normal Map Storing:", key)
			normal_map[key] = fmt.Sprintf("%v", key)
			fmt.Println("Normal Map Stored:", key, len(normal_map))
		}(key)
	}

	for len(normal_map) < NUM {
		time.Sleep(1)
	}

	fmt.Println("Normal Map Done")
}

func testSyncMap() {
	fmt.Println("testSyncMap")

	var sync_map sync.Map = sync.Map{}
	MapLength := 0

	for key := 0; key < NUM; key++ {
		go func(key int) {
			fmt.Println("Sync Map Storing:", key)
			sync_map.Store(key, fmt.Sprintf("%v", key))
			MapLength++
			fmt.Println("Sync Map Stored:", key, MapLength)
		}(key)
	}

	for MapLength < NUM {
	}

	fmt.Println("Sync Map Done")
}
