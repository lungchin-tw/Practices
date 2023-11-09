package exception_test

import (
	"fmt"
	"net/http"
	"reflect"
	"testing"

	"github.com/pkg/errors"
)

type GameError interface {
	ErrorCode() int
}

type GameAPIError interface {
	error
	GameError
	StatusCode() int
}

type sentinelGameAPIError struct {
	error
	error_code  int
	status_code int
}

func (e *sentinelGameAPIError) ErrorCode() int {
	return e.error_code
}

func (e *sentinelGameAPIError) StatusCode() int {
	return e.status_code
}

type LandErrorCode int

const (
	InvalidLandID LandErrorCode = 100
)

func (code LandErrorCode) Int() int {
	return int(code)
}

func NewInvalidLandID(landid []byte) error {
	return &sentinelGameAPIError{
		error:       fmt.Errorf("Land ID %X not found", landid),
		status_code: http.StatusNotFound,
		error_code:  InvalidLandID.Int(),
	}
}

func TestBuiltinErrType_errorString(t *testing.T) {
	e := errors.New("errorString")
	t.Logf("tyep of e: %v", reflect.TypeOf(e))
	t.Logf("e:%v", e)
	_, ok := e.(GameAPIError)
	t.Logf("e.(GameAPIError):%v", ok)
}

func throwCause() error {
	e := errors.New("cause")
	e2 := errors.Wrap(e, "TestBuiltinErrType_cause")
	e3 := errors.Cause(e2)
	return e3
}

func TestBuiltinErrType_cause(t *testing.T) {

	// t.Logf("e: %v", reflect.TypeOf(e))
	// t.Logf("e: %#v", e)
	// t.Logf("e2: %v", reflect.TypeOf(e2))
	// t.Logf("e2: %#v", e2)
	e := throwCause()
	t.Logf("e3: %#v", reflect.TypeOf(e))
	t.Logf("e3: %#v", e)
}

func TestBuiltinErrType_InvalidLandID(t *testing.T) {
	e := NewInvalidLandID([]byte{1, 2, 3, 4, 5})
	t.Logf("tyep of e: %v", reflect.TypeOf(e))
	t.Logf("e:%v", e)
	_, ok := e.(GameAPIError)
	t.Logf("e.(GameAPIError):%v", ok)
	switch v := e.(type) {
	case GameAPIError:
		t.Log("e.(type) = GameAPIError")
	default:
		t.Logf("e.(type) = %v", v)
	}
}
