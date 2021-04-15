package encode_test

import (
	"encoding/base64"
	"testing"
)

func TestBase64Case01(t *testing.T) {
	t.Run("jacky", func(t *testing.T) { RunBase64Case01(t, "jacky") })
	t.Run("201903", func(t *testing.T) { RunBase64Case01(t, "201903") })
}

func RunBase64Case01(t *testing.T, value string) {
	encoded := base64.StdEncoding.EncodeToString([]byte(value))
	t.Log(encoded)
	decoded, err := base64.StdEncoding.DecodeString(encoded)
	t.Log(string(decoded), err)
}
