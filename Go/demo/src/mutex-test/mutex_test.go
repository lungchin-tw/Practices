package mutextest

import (
	"fmt"
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

func TestNewMutex(t *testing.T) {
	wg := sync.WaitGroup{}
	mutexGroup := sync.Map{}
	num := 3
	wg.Add(num)
	for i := 0; i < num; i++ {
		go func(index int) {
			key := fmt.Sprintf("key:%v", index)
			value, loaded := mutexGroup.LoadOrStore(key, &sync.Mutex{})
			t.Logf("i=%v, Key=%v, Value:%p, Loaded:%v", index, key, value, loaded)
			mutex := value.(*sync.Mutex)
			mutex.Lock()
			t.Logf("i=%v, Key=%v, Locked.", index, key)
			defer mutex.Unlock()
			defer wg.Done()
		}(i)
	}

	wg.Add(num)
	for j := 0; j < num; j++ {
		go func(index int) {
			key := fmt.Sprintf("key:%v", index)
			value, loaded := mutexGroup.LoadOrStore(key, &sync.Mutex{})
			t.Logf("j=%v, Key=%v, Value:%p, Loaded:%v", index, key, value, loaded)

			mutex := value.(*sync.Mutex)
			mutex.Lock()
			t.Logf("j=%v, Key=%v, Locked.", index, key)
			defer mutex.Unlock()
			defer wg.Done()
		}(j)
	}

	wg.Wait()
}
