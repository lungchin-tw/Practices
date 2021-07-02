package main

import (
	"fmt"
	"regexp"
	"strings"
	"testing"
)

func TestRegexpCase01(t *testing.T) {
	{
		m, err := regexp.MatchString("foo.", "seafood")
		t.Logf(`regexp.MatchString("foo.", "seafood"), m=%v, err=%v`, m, err)
	}

	{
		m, err := regexp.MatchString("^foo", "seafood")
		t.Logf(`regexp.MatchString("^foo", "seafood"), m=%v, err=%v`, m, err)
	}

	{
		m, err := regexp.MatchString("bar.*", "seafood")
		t.Logf(`regexp.MatchString("bar.*", "seafood"), m=%v, err=%v`, m, err)
	}

	{
		m, err := regexp.MatchString("a(b", "seafood")
		t.Logf(`regexp.MatchString("a(b", "seafood") , m=%v, err=%v`, m, err)
	}
}

func TestRegexpCase02(t *testing.T) {
	p := "I am learning Go language"
	expr := "[a-z]{2,4}"
	t.Log("TEXT:", p)
	t.Log("EXPR:", expr)

	re, err := regexp.Compile(expr)
	if err != nil {
		t.Fatal(err)
	}

	t.Log("re.Find():", string(re.Find([]byte(p))))
	t.Log("re.FindAllString():", re.FindAllString(p, -1))
	t.Log("re.FindIndex()", re.FindIndex([]byte(p)))
	t.Log("re.FindIndex()", re.FindAllIndex([]byte(p), -1))
}

func TestRegexpCase03(t *testing.T) {
	p := "I am learning Go language"
	expr := "am(.*)lang(.*)"
	t.Log("TEXT:", p)
	t.Log("EXPR:", expr)

	re, err := regexp.Compile(expr)
	if err != nil {
		t.Fatal(err)
	}

	t.Logf("re.FindStringSubmatch(): %#v", re.FindStringSubmatch(p))
	t.Logf("re.FindAllStringSubmatch: %#v", re.FindAllStringSubmatch(p, -1))
}

func TestRegexpCase04(t *testing.T) {
	p := []byte(`
		call hello alice
		hello bob
		call hello eve
	`)
	expr := `(?m)(call)\s+(?P<cmd>\w+)\s+(?P<arg>.+)\s*$`
	t.Log("TEXT:", string(p))
	t.Log("EXPR:", expr)

	pat := regexp.MustCompile(expr)
	res := []byte{}
	for _, s := range pat.FindAllSubmatchIndex(p, -1) {
		res = pat.Expand(res, []byte("$cmd('$arg')\n"), p, s)
	}
	fmt.Println(string(res))
}

func TestRegexpCase05(t *testing.T) {
	p := "I am learning Go language"
	expr := "a[a-z]"
	t.Log("TEXT:", p)
	t.Log("EXPR:", expr)

	re, err := regexp.Compile(expr)
	if err != nil {
		t.Fatal(err)
	}

	t.Log("re.FindAllString():", re.FindAllString(p, -1))
}

func TestRegexpCase06(t *testing.T) {
	texts := map[string]string{
		"/:param":             "/test",
		"/users/:uid([0-9]+)": "/users/1234",
	}

	for k, v := range texts {
		t.Run(v, func(t *testing.T) { RunTestRegexpCase06(k, v, t) })
	}
}

func RunTestRegexpCase06(pattern string, value string, t *testing.T) {
	t.Log("PATTERN BEFORE:", pattern)
	t.Log("VALUE:", value)

	parts := strings.Split(pattern, "/")
	t.Logf("PARTS BEFORE: %#v", parts)

	j := 0
	params := make(map[int]string)
	for i, v := range parts {
		if strings.HasPrefix(v, ":") {
			expr := "([^/]+)"
			if index := strings.Index(v, "("); index != -1 {
				expr = v[index:]
				v = v[:index]
			}

			params[j] = v
			parts[i] = expr
			j++
		}
	}

	t.Logf("PARAMS: %#v", params)
	t.Logf("PARTS AFTER: %#v", parts)

	pattern = strings.Join(parts, "/")
	t.Log("PATTERN AFTER:", pattern)

	if regex, err := regexp.Compile(pattern); err != nil {
		t.Error(err)
	} else {
		t.Log("regex.MatchString:", regex.MatchString(value))
		t.Log("regex.FindStringSubmatch:", regex.FindStringSubmatch(value))
	}
}
