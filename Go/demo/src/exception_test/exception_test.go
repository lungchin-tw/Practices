package exception_test

import (
	"errors"
	"fmt"
	"log"
	"testing"
)

func DoFatal(err error) {
	defer fmt.Println("defer DoFatal")
	log.Fatalf("[DoFatal], Err:%v", err)
}

func DoPanic(err error) {
	defer fmt.Println("defer DoPanic")
	log.Panicf("[DoPanic], Err:%v", err)
}

func TestException(t *testing.T) {
	defer t.Log("defer TestException")

	err := errors.New("Access DB error!!!")
	t.Logf("err: %v", err)
	t.Logf("errors.Unwrap: %+v", errors.Unwrap(err))

	{
		err := fmt.Errorf("%v: %w", "Wrapper", errors.New("Be Wrapped"))
		t.Logf("\n[wrapError], %+v", err)
		t.Logf("[wrapError.Unwrap], %+v", errors.Unwrap(err))
	}
}

func TestFatal(t *testing.T) {
	DoFatal(errors.New("TestFatal"))
	fmt.Println("After Fatal")
}

func TestPanic(t *testing.T) {
	DoPanic(errors.New("TestPanic"))
	fmt.Println("After Panic")
}
