package conf

import "time"

const (
	MAX_CONN_NUM      = 2000
	PENDING_WRITE_NUM = 2000
	MAX_MSG_LEN       = 4096
	JSON_WSADDR       = "0.0.0.0:7766"
	JSON_TCPADDR      = "0.0.0.0:7777"
	PROTO_WSADDR      = "0.0.0.0:7788"
	PROTO_TCPADDR     = "0.0.0.0:7799"
	HTTP_TIMEOUT      = 10 * time.Second
	LEN_MSG_LEN       = 2
	IS_LITTLE_ENDIAN  = false
	CONSOLE_PORT      = 3333
)
