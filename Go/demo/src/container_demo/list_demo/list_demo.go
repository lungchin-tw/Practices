package main

import (
	"container/list"
	"fmt"
)

func main() {
	l := list.New()
	fmt.Println("l.PushBack(4),", l.PushBack(4))
	fmt.Println("l.PushBack(3),", l.PushBack(3))
	fmt.Println("l.PushFront(1),", l.PushFront(1))
	for p := l.Front(); p != nil; p = p.Next() {
		fmt.Println(p.Value)
	}
}
