package main

import "time"

import "fmt"

func main() {
	t := time.Now()

	fmt.Println("time.Now():", t)
	fmt.Println("time.Now().UTC():", t.UTC())
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
}
