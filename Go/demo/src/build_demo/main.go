package main

import "fmt"

/*
** try: go build,
** go build -tags prod,
** go build -ldflags "-X main.version=foobar",
** go build -ldflags "-X main.releaseTimestamp=foobar",
** go build -tags prod -ldflags "-X main.releaseTimestamp=foobar",
** go build -ldflags "-X main.releaseTimestamp=$(git rev-parse HEAD)",
** and see their difference
 */

var releaseTimestamp = "development"

func main() {
	fmt.Println("Running Version:", version)
	fmt.Println("Release Timestamp:", releaseTimestamp)
}
