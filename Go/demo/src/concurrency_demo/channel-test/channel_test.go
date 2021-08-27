package channeltest

import (
	"testing"
	"time"
)

func TestChannel01(t *testing.T) {
	c := make(chan int)

	go func() {
		t.Log("DONE: Go Routine.")
		c <- 1
		t.Log("DONE by Sender.")
	}()

	t.Log("DO Something.")
	t.Log("DONE By Receiver,", <-c)
}

func TestChannel02(t *testing.T) {
	c := make(chan int)

	for i := 0; i < 10; i++ {
		go func(i int) {
			t.Log("Go Routine,", i)
			c <- i
			t.Log("Sender,", i)
		}(i)

	}

	t.Log("DO Something.")

	for i := 0; i < 10; i++ {
		t.Log("Receiver,", <-c)
	}

	t.Log("All Done.")
}

func TestChannel03(t *testing.T) {
	c := make(chan int, 3)
	t.Log("cap(c),", cap(c))

	for i := 0; i < 10; i++ {
		go func(i int) {
			t.Log("Go Routine,", i)
			c <- i
			t.Log("Sender,", i)
		}(i)

	}

	t.Log("DO Something.")

	for i := 0; i < 10; i++ {
		t.Log("Receiver,", <-c)
	}

	t.Log("All Done.")
}

func TestChannel04(t *testing.T) {
	queue := make(chan int, 2)
	quit := make(chan int)
	counter := 0
	const TOTAL_NUM = 40

	t.Log("cap(queue),", cap(queue))

	for i := 0; i < 3; i++ {
		go func(queue chan int, i int) {
			t.Log("Launching Go Routine,", i)
			for value := range queue {
				t.Logf("[%v], Value=%v\n", i, value)
				counter++
				if counter >= TOTAL_NUM {
					t.Logf("[%v], Sending Quit.\n", i)
					quit <- 1
				}
			}
		}(queue, i)
	}

	for i := 0; i < TOTAL_NUM; i++ {
		queue <- i
	}

	<-quit
	t.Log("All Done.")
}

func TestChannel05(t *testing.T) {
	ca := make(chan *int, 5)

	go func() {
		for i := 0; i < 5; i++ {
			time.Sleep(time.Second)
			ca <- &i
		}

		ca <- nil
	}()

	for v := range ca {
		t.Log("v:", v)
		if v == nil {
			break
		}
	}
}
