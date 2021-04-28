package log_test

import (
	"bytes"
	"log"
	"testing"
)

func TestLog(t *testing.T) {
	var buf bytes.Buffer
	logger := log.New(&buf, "logger:", log.Lshortfile)

	logger.Print("Hello, log file!")
	// logger.Fatalln("logger.Fatalln")
	t.Log(&buf)
	// log.Fatalln("log.Fataln")
	log.Fatalf("Fatalf:%v", buf)
}
