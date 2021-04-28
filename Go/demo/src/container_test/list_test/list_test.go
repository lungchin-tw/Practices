package list_test

import (
	"container/list"
	"testing"
)

func TestList(t *testing.T) {
	l := list.New()
	t.Log("l.PushBack(4),", l.PushBack(4))
	t.Log("l.PushBack(3),", l.PushBack(3))
	t.Log("l.PushFront(1),", l.PushFront(1))
	for p := l.Front(); p != nil; p = p.Next() {
		t.Log(p.Value)
	}
}
