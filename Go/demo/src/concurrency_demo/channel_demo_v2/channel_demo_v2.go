package main

import (
	"fmt"
	"math/rand"
	"time"
)

type TPlayer struct {
	ID uint64
}

var ShutdownChan chan bool = make(chan bool)
var PlayerChan chan *TPlayer = make(chan *TPlayer, 1000)
var NumPlayer int
var TotalNumPlayer int
var GlobalPlayerUniqueID uint64

func main() {
	rand.Seed(time.Now().UTC().UnixNano())

	go func() {
		for player := range PlayerChan {
			NumPlayer++
			fmt.Printf("[%v/%v], %v\n", NumPlayer, TotalNumPlayer, *player)
		}
	}()

	go func() {
		for {
			num := rand.Intn(50) + rand.Intn(50)
			TotalNumPlayer += num
			fmt.Println("Total Generated Num Player:", TotalNumPlayer)

			for i := 0; i < num; i++ {
				GlobalPlayerUniqueID++
				PlayerChan <- &TPlayer{ID: GlobalPlayerUniqueID}
			}

			sleep := time.Duration(rand.Intn(10)) * time.Second
			fmt.Println("Sleep:", sleep)
			time.Sleep(sleep)
		}
	}()

	<-ShutdownChan
}
