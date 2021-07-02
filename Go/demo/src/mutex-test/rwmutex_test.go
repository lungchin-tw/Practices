package mutextest

import (
	"log"
	"sync"
	"testing"
	"time"
)

type BankRWMutex struct {
	balance int64
	mux     sync.RWMutex
}

func (this *BankRWMutex) Deposit(value int64) {
	this.mux.Lock()
	defer this.mux.Unlock()
	time.Sleep(time.Second)

	this.balance += value
}

func (this *BankRWMutex) Balance() int64 {
	this.mux.RLock()
	defer this.mux.RUnlock()

	time.Sleep(time.Second)
	return this.balance
}

func TestRWMutex(t *testing.T) {
	wg := sync.WaitGroup{}
	bank := &BankRWMutex{}
	const amount int64 = 10
	num := 5

	wg.Add(num)
	for i := 0; i < num; i++ {
		go func() {
			log.Println("Read Balance:", bank.Balance())
			wg.Done()
		}()
	}

	wg.Add(num)
	for i := 0; i < num; i++ {
		go func() {
			bank.Deposit(amount)
			log.Println("Write Deposite:", amount)
			wg.Done()
		}()
	}

	wg.Wait()
}
