package main

import (
	"fmt"
	"time"

	"golang.org/x/text/language"
	"golang.org/x/text/message"
)

func main() {
	t := time.Now()

	fmt.Println("time.Now():", t)
	fmt.Println("time.Now().UTC():", t.UTC())
	fmt.Println("time.Now().UTC().UnixNano():", t.UTC().UnixNano())
	fmt.Println("time.Now().Format(\"15-04-05\"):", t.Format("15-04-05"))
	fmt.Println("time.Day():", t.Day())
	fmt.Println("time.Hour():", t.Hour())
	fmt.Println("time.IsZero():", t.IsZero())
	fmt.Println("time.Local():", t.Local())
	fmt.Println("time.Location():", *(t.Location()))
	fmt.Println("time.Minute():", t.Minute())
	fmt.Println("time.Month():", t.Month())
	fmt.Println("time.Nanosecond():", t.Nanosecond())
	fmt.Println("time.Second():", t.Second())
	fmt.Println("time.String():", t.String())
	fmt.Println("time.Weekday():", t.Weekday())
	fmt.Println("time.Year():", t.Year())
	fmt.Println("time.YearDay():", t.YearDay())

	printer := message.NewPrinter(language.English)

	fmt.Println("\nUNITS:")
	printer.Println("time.Millisecond:", int64(time.Millisecond))
	printer.Println("time.Second:", int64(time.Second))
	printer.Println("time.Minute:", int64(time.Minute))
	t2 := t.Add(time.Minute * 2)
	printer.Println("time.Add(time.Minute):", t2)
	printer.Println("(t2 > t):", (t2.After(t)))
	printer.Println("(t2 == t):", (t2 == t))
	printer.Println("(t2 < t):", (t2.Before(t)))
}
