package test

import (
	"bytes"
	"log"
	"testing"
)

func TestLogCase01(t *testing.T) {
	var buf bytes.Buffer
	logger := log.New(&buf, "[case01]", log.Lshortfile)

	logger.Print("Hello, log file!")
	// logger.Fatalln("logger.Fatalln")
	t.Log(&buf)
	// log.Fatalln("log.Fataln")
	// log.Fatalf("Fatalf:%v", buf)
}

func TestLogCase02(t *testing.T) {
	var buf bytes.Buffer
	logger := log.New(&buf, "[case02]", log.LstdFlags|log.Lshortfile)

	logger.Print("logger.Print")
	t.Log(&buf)

	runCallDepth(t, logger)
}

func runCallDepth(t *testing.T, logger *log.Logger) {
	logger.Output(1, "Call Depth = 1")
	logger.Output(2, "Call Depth = 2")
	logger.Output(3, "Call Depth = 3")

	t.Log(logger.Writer())
}
