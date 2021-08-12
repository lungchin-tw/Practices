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

func TestTime02(t *testing.T) {
	nano := time.Now().UnixNano()
	utcnano := time.Now().UTC().UnixNano()
	t.Log("time.Now().UnixNano():", nano)
	t.Log("time.Now().UTC().UnixNano():", utcnano)
	t.Log("diff", nano-utcnano)

	t.Log("Unix:", time.Unix(0, 1627356276863375600))
	t.Log("Unix:", time.Unix(0, 1627356276863375600).UTC())
}

func TestTimeFormatting(t *testing.T) {
	now := time.Now()
	t.Logf("[%v:%v], %v", "time.ANSIC", time.ANSIC, now.Format(time.ANSIC))
	t.Logf("[%v:%v], %v", "time.UnixDate", time.UnixDate, now.Format(time.UnixDate))
	t.Logf("[%v:%v], %v", "UTC time.UnixDate", time.UnixDate, now.UTC().Format(time.UnixDate))
	t.Logf("[%v:%v], %v", "time.RubyDate", time.RubyDate, now.Format(time.RubyDate))
	t.Logf("[%v:%v], %v", "UTC time.RubyDate", time.RubyDate, now.UTC().Format(time.RubyDate))
	t.Logf("[%v:%v], %v", "time.RFC822", time.RFC822, now.Format(time.RFC822))
	t.Logf("[%v:%v], %v", "time.RFC822Z", time.RFC822Z, now.Format(time.RFC822Z))
	t.Logf("[%v:%v], %v", "time.RFC850", time.RFC850, now.Format(time.RFC850))
	t.Logf("[%v:%v], %v", "time.RFC1123", time.RFC1123, now.Format(time.RFC1123))
	t.Logf("[%v:%v], %v", "time.RFC1123Z", time.RFC1123Z, now.Format(time.RFC1123Z))
	t.Logf("[%v:%v], %v", "time.RFC3339", time.RFC3339, now.Format(time.RFC3339))
	t.Logf("[%v:%v], %v", "time.RFC3339Nano", time.RFC3339Nano, now.Format(time.RFC3339Nano))
	t.Logf("[%v:%v], %v", "time.Kitchen", time.Kitchen, now.Format(time.Kitchen))
	t.Logf("[%v:%v], %v", "time.Stamp", time.Stamp, now.Format(time.Stamp))
	t.Logf("[%v:%v], %v", "time.StampMilli", time.StampMilli, now.Format(time.StampMilli))
	t.Logf("[%v:%v], %v", "time.StampMicro", time.StampMicro, now.Format(time.StampMicro))
	t.Logf("[%v:%v], %v", "time.StampNano", time.StampNano, now.Format(time.StampNano))

	{
		const custom = "Monday January 2 15:04:05.000 2006"
		t.Logf("[%v:%v], %v", "CUSTOM", custom, now.Format(custom))
	}

	{
		const custom = "2006-Jan-02 __2 15:04:05 -07:00"
		t.Logf("[%v:%v], %v", "CUSTOM", custom, now.Format(custom))
	}
}
