package reflect_test

import (
	"reflect"
	"testing"
)

/**
** 1. Reflection goes from interface value to reflection object.
** 2. Reflection goes from reflection object to interface value.
** 3. To modify a reflection object, the value must be settable.
 */

// 1. Reflection goes from interface value to reflection object.
func TestReflectLaws01(t *testing.T) {
	t.Run("Float64", func(t *testing.T) {
		var x float64 = 3.4
		RunReflectLaws01(x, t)
	})

	type MyInt int
	t.Run("MyType", func(t *testing.T) {
		var x MyInt = 10
		RunReflectLaws01(x, t)
	})
}

func RunReflectLaws01(x interface{}, t *testing.T) {
	t.Logf("Type of %v: %v", x, reflect.TypeOf(x))
	v := reflect.ValueOf(x)
	t.Logf("Value of %v: %v", x, v)
	t.Logf("Type of %v: %v", x, v.Type())
	t.Logf("Kind of %v: %v", x, v.Kind())

	switch v.Kind() {
	case reflect.Float64:
		t.Logf("Float of %v: %v", x, v.Float())
	case reflect.Int:
		t.Logf("Int of %v: %v", x, v.Int())
	}

	t.Logf("String of %v: %v", x, reflect.ValueOf(x).String())
}

// 2. Reflection goes from reflection object to interface value.
func TestReflectLaws02(t *testing.T) {
	var x float64 = 3.4
	v := reflect.ValueOf(x)
	t.Log("interface of Value:", v.Interface())
}

// 3. To modify a reflection object, the value must be settable.
func TestReflectLaws03(t *testing.T) {
	var x float64 = 3.4
	{
		v := reflect.ValueOf(x)
		t.Logf("Settability of Value(%v %v):%v", x, v.Type(), v.CanSet())
	}

	{
		p := reflect.ValueOf(&x)
		t.Logf("Settability of Value(%v %v):%v", &x, p.Type(), p.CanSet())
		v := p.Elem()
		t.Logf("Settability of Elem(%v %v):%v", p, v.Type(), v.CanSet())
		t.Log("Before:", v.Interface())
		v.SetFloat(6.2)
		t.Log("After:", v.Interface())
	}
}

func TestReflectionStruct(t *testing.T) {
	type T struct {
		A int
		B string
	}

	obj := T{23, "skidoo"}
	s := reflect.ValueOf(&obj).Elem()
	typeoft := s.Type()
	for i := 0; i < s.NumField(); i++ {
		f := s.Field(i)
		t.Logf(
			"%v: %v %v %v = %v",
			i,
			typeoft.Field(i).Name,
			f.Type(),
			typeoft.Field(i).Type,
			f.Interface(),
		)
	}
}
