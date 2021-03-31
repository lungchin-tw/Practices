package main

import (
	"fmt"
	"regexp"
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
	re, err := regexp.Compile("[a-z]{2,4}")
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
	re, err := regexp.Compile("am(.*)lang(.*)")
	if err != nil {
		t.Fatal(err)
	}

	re.FindStringSubmatch(p)
	t.Logf("re.FindStringSubmatch(): %#v", re.FindStringSubmatch(p))
	t.Logf("re.FindAllStringSubmatch: %#v", re.FindAllStringSubmatch(p, -1))
}

func TestRegexpCase04(t *testing.T) {
	src := []byte(`
		call hello alice
		hello bob
		call hello eve
	`)
	pat := regexp.MustCompile(`(?m)(call)\s+(?P<cmd>\w+)\s+(?P<arg>.+)\s*$`)
	res := []byte{}
	for _, s := range pat.FindAllSubmatchIndex(src, -1) {
		res = pat.Expand(res, []byte("$cmd('$arg')\n"), src, s)
	}
	fmt.Println(string(res))
}
