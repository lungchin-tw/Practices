package main

import (
	"fmt"
	"strconv"
	"strings"
	"time"
)

func main() {
	str := " x y z "
	fmt.Printf("strings.TrimSpace(%v) = (%v)\n", str, strings.TrimSpace(str))
	fmt.Printf("strings.Trim(%v, \"\\t \"\\n\") = (%v)\n", str, strings.Trim(str, "\t \n"))

	{
		filename := "123.456"
		index := strings.LastIndex(filename, ".")
		fmt.Printf("strings.LastIndex(%v, \".\"): %v\n", filename, index)
		slice := filename[:index]
		fmt.Println("slice:", slice)
	}

	{
		ext := ".docx"
		if ext[0] == '.' {
			ext = ext[1:]
		}

		fmt.Println("ext:", ext)

		if ext[0] != '.' {
			ext = "." + ext
		}

		fmt.Println("ext:", ext)
	}

	// Split
	{
		timestamp := "2020-03-05T06:35:02.705820"
		phase1 := strings.Split(timestamp, "T")
		fmt.Printf("Split %v: %#v\n", timestamp, phase1)

		phase2 := strings.Split(phase1[0], "-")
		fmt.Printf("Split %v: %#v\n", phase1[0], phase2)

		phase3 := strings.Split(phase1[1], ".")
		fmt.Printf("Split %v: %#v\n", phase1[1], phase3)

		phase4 := strings.Split(phase3[0], ":")
		fmt.Printf("Split %v: %#v\n", phase3[0], phase4)

		year, _ := strconv.Atoi(phase2[0])
		month, _ := strconv.Atoi(phase2[1])
		day, _ := strconv.Atoi(phase2[2])
		hour, _ := strconv.Atoi(phase4[0])
		min, _ := strconv.Atoi(phase4[1])
		sec, _ := strconv.Atoi(phase4[2])
		date := time.Date(year, time.Month(month), day, hour, min, sec, 0, time.Now().Location())
		fmt.Printf("Final Data Result: %v\n", date)

		var datetime time.Time

		fmt.Printf("datetime: %#v, IsZero=%v\n", datetime, datetime.IsZero())

	}

}
