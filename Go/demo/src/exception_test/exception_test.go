package exception_test

import (
	"errors"
	"fmt"
	"log"
	"testing"
)

func DoFatal(err error) {
	defer fmt.Println("defer DoFatal")
	log.Fatalf("Err:%v", err)
}

func DoPanic(err error) {
	defer fmt.Println("defer DoPanic")
	log.Panicf("Err:%v", err)
}

func TestException(t *testing.T) {
	defer t.Log("defer main")

	err := errors.New("Access DB error!!!")
	t.Logf("err: %v", err)
	t.Logf("err: %+v", err)
	t.Logf("err: %v", err.Error())
	t.Logf("errors.Unwrap: %+v", errors.Unwrap(err))

	// DoFatal(err)
	// fmt.Println("After Fatal")

	// DoPanic(err)
	// fmt.Println("After Panic")

	{
		err := fmt.Errorf("%v: %w", "Wrapper", errors.New("Be Wrapped"))
		t.Logf("\n[wrapError], %+v", err)
		t.Logf("[wrapError.Unwrap], %+v", errors.Unwrap(err))
	}
}
