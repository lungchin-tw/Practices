package reflect_test

import (
	"reflect"
	"runtime"
	"testing"
)

func getLength(in interface{}) int {
	return reflect.ValueOf(in).Len()
}

type SubGame struct {
	subGameName string
}

type Game struct {
	GameID   int
	GameName string
	players  []uint64
	subGame  SubGame
}

func TestReflectSliceCase01(t *testing.T) {
	slice := make([]int, 10)
	v := reflect.ValueOf(slice)
	t.Log("Kind:", v.Kind())
	t.Log("Len:", v.Len())
}

func TestReflectArrayCase01(t *testing.T) {
	array := [2]int{}
	v := reflect.ValueOf(array)
	t.Log("Kind:", v.Kind())
	t.Log("Len:", v.Len())
}

func TestReflectStructCase01(t *testing.T) {
	thetype := reflect.TypeOf(Game{})
	t.Log("reflect.TypeOf(Game{}):", thetype)
	t.Log("thetype.Align():", thetype.Align())
	t.Log("thetype.FieldAlign():", thetype.FieldAlign())
	t.Log("thetype.NumMethod():", thetype.NumMethod())
	t.Log("thetype.Name():", thetype.Name())
	t.Log("thetype.PkgPath():", thetype.PkgPath())
	t.Log("thetype.PkgPath():", thetype.PkgPath())
	t.Log("thetype.String():", thetype.String())
	t.Log("thetype.Kind():", thetype.Kind())
	t.Log("thetype.Comparable():", thetype.Comparable())
	// t.Log("thetype.Bits():", thetype..Bits())
	// t.Log("thetype.ChanDir():", thetype..ChanDir())
	// t.Log("thetype.IsVariadic():", thetype..IsVariadic())
	// t.Log("thetype.Elem():", thetype..Elem())
	// t.Log("thetype.Key():", thetype..Key())
	// t.Log("thetype.Len():", thetype..Len())
	t.Log("thetype.NumField():", thetype.NumField())
	// t.Log("thetype.NumIn():", thetype.NumIn())
	// t.Log("thetype.NumOut():", thetype.NumOut())
	for i := 0; i < thetype.NumField(); i++ {
		field := thetype.FieldByIndex([]int{i})
		t.Logf("Field[%v], Kind:%v", i, field.Type.Kind())
		if field.Type.Kind() == reflect.Struct {
			field = thetype.FieldByIndex([]int{i, 0})
			t.Logf("Field[%v], %#v", []int{i, 0}, field)
		} else {
			t.Logf("Field[%v], %#v", i, field)
		}
	}
}

type ProtoBufMarshaler interface {
	ProtoBuf() (interface{}, error)
}

type TFreeGameOption struct {
}

func (this *TFreeGameOption) ProtoBuf() (interface{}, error) {
	return nil, nil
}

func TestReflectStructCase02(t *testing.T) {
	var src interface{} = &TFreeGameOption{}
	t.Logf("Type:%+v, Value:%+v", reflect.TypeOf(src), reflect.ValueOf(src))
}

func TestReflectFuncCase01(t *testing.T) {
	src := &TFreeGameOption{}

	{
		v := reflect.ValueOf(src.ProtoBuf)
		t.Logf("reflect.ValueOf(src.ProtoBuf): %#v", v)
		pc := runtime.FuncForPC(v.Pointer())
		t.Logf("runtime.FuncForPC(v.Pointer()): %#v", pc)
		t.Logf("pc.Name(): %#v", pc.Name())
	}

	{
		v := reflect.ValueOf(src)
		t.Logf("reflect.ValueOf(src): %#v", v)
		pc := runtime.FuncForPC(v.Pointer())
		t.Logf("runtime.FuncForPC(v.Pointer()): %#v", pc)
		t.Logf("pc.Name(): %#v", pc.Name())
	}
}
