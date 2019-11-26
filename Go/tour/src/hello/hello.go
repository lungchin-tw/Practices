package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	seed := (time.Now().UTC().UnixNano())
	rand.Seed(seed)
	fmt.Println("seed: ", seed)
	fmt.Println("A random number: ", rand.Intn(10))
}
