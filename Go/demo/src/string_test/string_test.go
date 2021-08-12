package main

import (
	"encoding/json"
	"strconv"
	"strings"
	"testing"
	"time"
)

func TestStringCase01(t *testing.T) {
	str := " x y z "
	t.Logf("strings.TrimSpace(%v) = (%v)\n", str, strings.TrimSpace(str))
	t.Logf("strings.Trim(%v, \"\\t \"\\n\") = (%v)\n", str, strings.Trim(str, "\t \n"))
}

func TestStringCase02(t *testing.T) {
	{
		filename := "123.456"
		index := strings.LastIndex(filename, ".")
		t.Logf("strings.LastIndex(%v, \".\"): %v\n", filename, index)
		t.Logf("len:%v, strings.LastIndex(%v, \"56\"): %v\n", len(filename), filename, strings.LastIndex(filename, "56"))
		slice := filename[:index]
		t.Log("slice:", slice)
	}

	{
		ext := ".docx"
		if ext[0] == '.' {
			ext = ext[1:]
		}

		t.Log("ext:", ext)

		if ext[0] != '.' {
			ext = "." + ext
		}

		t.Log("ext:", ext)
	}
}

func TestStringCase03(t *testing.T) {
	timestamp := "2020-03-05T06:35:02.705820"
	phase1 := strings.Split(timestamp, "T")
	t.Logf("Split %v: %#v\n", timestamp, phase1)

	phase2 := strings.Split(phase1[0], "-")
	t.Logf("Split %v: %#v\n", phase1[0], phase2)

	phase3 := strings.Split(phase1[1], ".")
	t.Logf("Split %v: %#v\n", phase1[1], phase3)

	phase4 := strings.Split(phase3[0], ":")
	t.Logf("Split %v: %#v\n", phase3[0], phase4)

	year, _ := strconv.Atoi(phase2[0])
	month, _ := strconv.Atoi(phase2[1])
	day, _ := strconv.Atoi(phase2[2])
	hour, _ := strconv.Atoi(phase4[0])
	min, _ := strconv.Atoi(phase4[1])
	sec, _ := strconv.Atoi(phase4[2])
	date := time.Date(year, time.Month(month), day, hour, min, sec, 0, time.Now().Location())
	t.Logf("Final Data Result: %v\n", date)

	var datetime time.Time

	t.Logf("datetime: %#v, IsZero=%v\n", datetime, datetime.IsZero())
}

func TestStringCase04(t *testing.T) {
	str := make([]byte, 0, 10)
	t.Log(strconv.AppendInt(str, 4567, 10))
	t.Logf("%q", strconv.AppendInt(str, 4567, 10))
	t.Log(strconv.AppendBool(str, false))
	t.Logf("%q", strconv.AppendBool(str, false))
	t.Log(strconv.AppendQuote(str, "abcdefg"))
	t.Logf("%q", strconv.AppendQuote(str, "abcdefg"))
	t.Log(strconv.AppendQuoteRune(str, '買'))
	t.Logf("%q", strconv.AppendQuoteRune(str, '買'))
}

func TestStringCase05(t *testing.T) {
	t.Log(strconv.FormatBool(false))
	t.Log(strconv.FormatFloat(123.23, 'g', 12, 64))
	t.Log(strconv.FormatInt(1234, 10))
	t.Log(strconv.FormatUint(12345, 10))
	t.Log(strconv.Itoa(1023))
}

func TestStringCase06(t *testing.T) {
	t.Log(strconv.ParseBool("false"))
	t.Log(strconv.ParseFloat("123.23", 64))
	t.Log(strconv.ParseInt("1234", 10, 64))
	t.Log(strconv.ParseUint("12345", 10, 64))
}

func TestSliceStringFormat(t *testing.T) {
	v := []int{30, 10, 10, 0, 0}
	t.Logf("%%v: %v", v)
	t.Logf("%%+v: %+v", v)
	t.Logf("%%#v: %#v", v)
	t.Logf("%%q: %q", v)
	t.Logf("%%p: %p", v)

	t.Log("Jsonized:")
	bytes, _ := json.Marshal(v)
	t.Logf("%%v: %v", bytes)
	t.Logf("%%+v: %+v", bytes)
	t.Logf("%%#v: %#v", bytes)
	t.Logf("%%s: %s", bytes)
	t.Logf("%%q: %q", bytes)
	t.Logf("%%p: %p", bytes)
}

func TestPrintFormatter(t *testing.T) {
	{
		var value float64 = 10000000000.123456
		t.Logf("%%v=%v", value)
		t.Logf("%%f=%f", value)
	}

	{
		var value int64 = 1000000000000
		t.Logf("%%v=%v", value)
		t.Logf("%%d=%d", value)
	}
}
