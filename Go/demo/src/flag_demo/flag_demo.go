package main

import (
	"flag"
	"fmt"
)

var (
	ArgCount    = flag.Int("count", 5, "count of iteration")
	ArgGreeting = flag.String("greeting", "HI", "Say Greetings to Customer.")
)

func main() {
	// flag.PrintDefaults()
	flag.Visit(func(flag *flag.Flag) {
		fmt.Printf("flag.Visit, flag:%#v\n", *flag)
	})

	fmt.Printf("flag.Args():%#v\n", flag.Args())
	fmt.Println("Before flag.Parse(), ArgCount:", *ArgCount)
	flag.Parse()
	fmt.Println("After flag.Parse(), ArgCount:", *ArgCount)
	fmt.Printf("flag.Args():%#v, flag.NArg():%v\n", flag.Args(), flag.NArg())
	flag.Visit(func(flag *flag.Flag) {
		fmt.Printf("flag.Visit, flag:%#v\n", *flag)
	})
}
