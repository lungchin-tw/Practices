package main

import (
	"container/list"
	"fmt"
)

func main() {
	l := list.New()
	for i := 0; i < 10; i++ {
		l.PushBack(i)
	}

	e := l.Back()
	for e != nil {
		fmt.Println("Value:", e.Value)
		if e.Value.(int) == 7 {
			l.Remove(e)
		}

		e = e.Prev()
	}
}
