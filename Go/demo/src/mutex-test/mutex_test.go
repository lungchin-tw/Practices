package mutextest

import (
	"log"
	"sync"
	"testing"
	"time"
)

type BankMutex struct {
	balance int64
	mux     sync.Mutex
}

func (this *BankMutex) Deposit(value int64) {
	this.mux.Lock()
	defer this.mux.Unlock()
	time.Sleep(time.Second)

	this.balance += value
}

func (this *BankMutex) Balance() int64 {
	this.mux.Lock()
	defer this.mux.Unlock()
	time.Sleep(time.Second)

	return this.balance
}

func TestMutex(t *testing.T) {
	wg := sync.WaitGroup{}
	bank := &BankMutex{}
	const amount int64 = 10
	num := 5

	wg.Add(num)
	for i := 0; i < num; i++ {
		go func() {
			bank.Deposit(amount)
			log.Println("Write Deposite:", amount)
			wg.Done()
		}()
	}

	wg.Add(num)
	for i := 0; i < num; i++ {
		go func() {
			log.Println("Read Balance:", bank.Balance())
			wg.Done()
		}()
	}

	wg.Wait()
}
