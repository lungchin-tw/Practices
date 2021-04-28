package initialization_test

import (
	"fmt"
	"testing"
)

const (
	NONE int = iota * -1
	FIRST
	SECOND
	THIRD
)

func init() {
	fmt.Println("func init()")
}

func TestInitialization(t *testing.T) {
	t.Log("func main()")

	t.Log("NONE=", NONE)
	t.Log("FIRST=", FIRST)
	t.Log("SECOND=", SECOND)
	t.Log("THIRD=", THIRD)
}
