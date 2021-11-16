package cryptotest

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/md5"
	"crypto/rand"

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

func TestAES(t *testing.T) {
	value := []byte("My name is 傑克.")
	key := make([]byte, 32) // the key has to be 32 bytes long
	if n, err := rand.Read(key); err != nil {
		t.Fatal(err)
	} else {
		t.Log("rand.Read()", n, err)
	}

	encvalue, nonce, err := aesEncryption(t, value, key)
	if err != nil {
		t.Fatal(err)
	} else {
		t.Log("Encrypted Value:", encvalue)
		t.Log("Nonce:", nonce)
	}

	decvalue, err := aesDecryption(t, encvalue, key, nonce)
	if err != nil {
		t.Fatal(err)
	} else {
		t.Log("Decrypted Value:", decvalue)
		t.Log("Decrypted Value:", string(decvalue))
	}
}

func aesEncryption(t *testing.T, value, key []byte) (rtnEncValue, rtnNonce []byte, rtnErr error) {
	t.Log("aesEncryption, value:", value)
	t.Log("aesEncryption, value:", string(value))
	t.Log("aesEncryption, key:", key)

	block, err := aes.NewCipher(key)
	if err != nil {
		t.Fatal(err)
	}

	gcm, err := cipher.NewGCM(block)
	if err != nil {
		t.Fatal(err)
	}

	t.Log("gcm.NonceSize():", gcm.NonceSize())

	nonce := make([]byte, gcm.NonceSize())
	if n, err := rand.Read(nonce); err != nil {
		t.Fatal(err)
	} else {
		t.Log("rand.Read()", n, err)
	}

	return gcm.Seal(nil, nonce, value, nil), nonce, nil
}

func aesDecryption(t *testing.T, encvalue, key, nonce []byte) ([]byte, error) {
	t.Log("aesDecryption, value:", encvalue)
	t.Log("aesDecryption, key:", key)

	block, err := aes.NewCipher(key)
	if err != nil {
		t.Fatal(err)
	}

	gcm, err := cipher.NewGCM(block)
	if err != nil {
		t.Fatal(err)
	}

	noncesize := gcm.NonceSize()
	t.Log("NonceSize:", noncesize)
	return gcm.Open(nil, nonce, encvalue, nil)
}
