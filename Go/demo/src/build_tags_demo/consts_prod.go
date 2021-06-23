// +build prod

package main

import (
	"fmt"
	"time"
)

const version = "production"

func init() {
	releaseTimestamp = fmt.Sprintf("%s-%s", version, time.Now())
}
