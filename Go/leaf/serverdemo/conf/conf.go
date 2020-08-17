package conf

import "time"

const (
	MAX_CONN_NUM      = 2000
	PENDING_WRITE_NUM = 2000
	MAX_MSG_LEN       = 4096
	WSADDR            = "0.0.0.0:6666"
	TCPADDR           = "0.0.0.0:7777"
	HTTP_TIMEOUT      = 10 * time.Second
	LEN_MSG_LEN       = 2
	IS_LITTLE_ENDIAN  = false
)
