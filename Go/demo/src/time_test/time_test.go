package time_test

import (
	"testing"
	"time"

	"golang.org/x/text/language"
	"golang.org/x/text/message"
)

func TestTime(t *testing.T) {
	now := time.Now()

	t.Log("time.Now():", now)
	t.Log("time.Now().UTC():", now.UTC())
	t.Log("time.Now().UTC().Unix():", now.UTC().Unix())
	t.Log("time.Now().Local().Unix():", now.Local().Unix())
	t.Log("time.Now().UTC().UnixNano():", now.UTC().UnixNano())
	t.Log("time.Now().Format(\"15-04-05\"):", now.Format("15-04-05"))
	t.Log("time.Day():", now.Day())
	t.Log("time.Hour():", now.Hour())
	t.Log("time.IsZero():", now.IsZero())
	t.Log("time.Local():", now.Local())
	t.Log("time.Location():", *(now.Location()))
	loc, _ := time.LoadLocation("Asia/Taipei")
	// loc, _ := time.LoadLocation("America/Los_Angeles")
	t.Log("time.In(time.LoadLocation(\"America/Los_Angeles\")):", now.In(loc))
	t.Log("time.Minute():", now.Minute())
	t.Log("time.Month():", now.Month())
	t.Log("time.Nanosecond():", now.Nanosecond())
	t.Log("time.Second():", now.Second())
	t.Log("time.String():", now.String())
	t.Log("time.Weekday():", now.Weekday())
	t.Log("time.Year():", now.Year())
	t.Log("time.YearDay():", now.YearDay())

	printer := message.NewPrinter(language.English)

	t.Log("\nUNITS:")
	printer.Println("time.Microsecond:", int64(time.Microsecond))
	printer.Println("time.Nanosecond:", int64(time.Nanosecond))
	printer.Println("time.Millisecond:", int64(time.Millisecond))
	printer.Println("time.Second:", int64(time.Second))
	printer.Println("time.Minute:", int64(time.Minute))

	after := now.Add(time.Minute * 2)
	printer.Println("time.Add(time.Minute):", after)
	printer.Println("(after > now):", (after.After(now)))
	printer.Println("(after == now):", (after == now))
	printer.Println("(after < now):", (after.Before(now)))

	t.Log("time.Unix(1578633001, 0).Local():", time.Unix(1578633001, 0).Local())
}