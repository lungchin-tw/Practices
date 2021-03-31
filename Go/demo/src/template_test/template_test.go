package template_test

import (
	"html/template"
	"os"
	"path/filepath"
	"runtime"
	"testing"
)

func CurFrame(skip int) runtime.Frame {
	pc := make([]uintptr, 1)
	num := runtime.Callers(skip, pc)
	if num <= 0 {
		return runtime.Frame{}
	}

	frame, _ := runtime.CallersFrames(pc).Next()
	return frame
}

func CurFile() string {
	return CurFrame(3).File
}

type Friend struct {
	Fname string
}

type Person struct {
	UserName string
	Emails   []string
	Friends  []*Friend
}

func TestTemplateCase01(t *testing.T) {
	tpl := template.New("fieldname example")
	tpl, _ = tpl.Parse("hello {{.UserName}}\n")
	data := struct {
		UserName string
	}{
		UserName: "Jacky",
	}

	tpl.Execute(os.Stdout, data)
}

func TestTemplateCase02(t *testing.T) {
	data := Person{
		UserName: "Jacky",
		Emails:   []string{"jacky@labsgl.com", "jacky@gmail.com"},
		Friends:  []*Friend{{Fname: "minux.ma"}, {Fname: "xushiwei"}},
	}

	tpl := template.New("example02")
	tpl, _ = tpl.Parse(`hello {{.UserName}}!
			{{range .Emails}}
				an email {{.}}
			{{end}}
			{{with .Friends}}
			{{range .}}
				my friend name is {{.Fname}}
			{{end}}
			{{end}}
			`)

	tpl.Execute(os.Stdout, data)
}

func TestTemplateCase03(t *testing.T) {
	empty := template.New("empty pipeline demo")
	empty = template.Must(empty.Parse(
		"Empty pipeline if demo: {{if ``}} will not be outputted. {{end}}\n",
	))
	empty.Execute(os.Stdout, nil)

	value := template.New("value pipeline demo")
	value = template.Must(value.Parse(
		"Value pipeline if demo: {{if `anything`}} will be outputted. {{end}}\n",
	))
	value.Execute(os.Stdout, nil)

	ifelse := template.New("ifelse pipeline demo")
	ifelse = template.Must(ifelse.Parse(
		"if-else demo: {{if `anything`}} if part {{else}} else part {{end}}\n",
	))
	ifelse.Execute(os.Stdout, nil)
}

func TestTemplateCase04(t *testing.T) {
	{
		variables := template.New("template variables  demo")
		variables = template.Must(variables.Parse(
			"{{with $x := \"output\" | printf \"%q\"}}{{$x}}{{end}}\n",
		))
		variables.Execute(os.Stdout, nil)
	}
	{
		variables := template.New("template variables  demo")
		variables = template.Must(variables.Parse(
			"{{with $x := \"output\"}}{{printf \"%q\" $x}}{{end}}\n",
		))
		variables.Execute(os.Stdout, nil)
	}
	{
		variables := template.New("template variables  demo")
		variables = template.Must(variables.Parse(
			"{{with $x := \"output\"}}{{$x | printf \"%q\"}}{{end}}\n",
		))
		variables.Execute(os.Stdout, nil)
	}
}

func TestTemplateCase05(t *testing.T) {
	var tplfilenames []string = []string{
		"layout.tmpl",
		"header.tmpl",
		"body.tmpl",
	}

	rootpath := filepath.Dir(CurFile())
	for index, filename := range tplfilenames {
		tplfilenames[index] = filepath.Join(rootpath, filename)
	}

	templates, err := template.ParseFiles(tplfilenames...)
	t.Log("Header:", templates.Lookup("header.tmpl"))
	t.Log("Templates:", templates)
	t.Log("Error:", err)

	templates.Execute(os.Stdout, nil)
}
