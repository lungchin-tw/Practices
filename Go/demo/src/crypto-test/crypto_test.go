package test

import (
	"crypto/md5"
	"crypto/sha1"
	"crypto/sha256"
	"hash"
	"io"
	"testing"

	"golang.org/x/crypto/bcrypt"
)

func TestHashing(t *testing.T) {
	value := "1234567890"
	t.Run("SHA256", func(t *testing.T) { RunHashing(value, sha256.New(), t) })
	t.Run("SHA1", func(t *testing.T) { RunHashing(value, sha1.New(), t) })
	t.Run("MD5", func(t *testing.T) { RunHashing(value, md5.New(), t) })
	t.Run("BCryptCase01", func(t *testing.T) { RunBCryptCase01(value, t) })
	t.Run("BCryptCase02", func(t *testing.T) { RunBCryptCase02(value, t) })
}

func RunHashing(value string, h hash.Hash, t *testing.T) {
	io.WriteString(h, value)
	t.Logf("%v", h.Sum(nil))
	t.Logf("%x", h.Sum(nil))
}

func RunBCryptCase01(value string, t *testing.T) {
	hash, err := bcrypt.GenerateFromPassword([]byte(value), bcrypt.DefaultCost)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("%v", hash)
	t.Logf("%x", hash)
}

func RunBCryptCase02(value string, t *testing.T) {
	hash, err := bcrypt.GenerateFromPassword([]byte(value), bcrypt.DefaultCost)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("%v", hash)
	t.Logf("%x", hash)

	if err := bcrypt.CompareHashAndPassword(hash, []byte(value)); err != nil {
		t.Fatal(err)
	}
}
