package socket_test

import (
	"flag"
	"net"
	"os"
	"testing"
)

var ip = flag.String("ip", "", "")

func TestSocketCase01(t *testing.T) {
	t.Log(os.Args)
	flag.Parse()

	if len(*ip) == 0 {
		t.Fatal("ip is empty")
	}

	addr := net.ParseIP(*ip)
	t.Log(addr)
}

func TestSocketCase02(t *testing.T) {
	t.Log(net.ResolveTCPAddr("tcp", "www.google.com:80"))
	t.Log(net.ResolveTCPAddr("tcp", "www.labsgl.com:30000"))
}
