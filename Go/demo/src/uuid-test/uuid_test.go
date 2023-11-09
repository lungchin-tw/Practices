package uuidtest

import (
	"testing"

	"github.com/google/uuid"
)

func TestUUID(t *testing.T) {
	t.Log(uuid.New().String())
}
