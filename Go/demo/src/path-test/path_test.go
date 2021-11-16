package main

import (
	"os"
	"path/filepath"
	"testing"
)

func TestPath(t *testing.T) {
	t.Log("Frame.File", GetCurFile())

	path, err := os.Getwd()
	t.Logf("os.Getwd()=%v, %v", path, err)

	for len(path) > 1 {
		path = filepath.Dir(path)
		t.Logf("filepath.Dir=%v", path)
	}

	t.Logf("os.Args=%#v", os.Args)
	dir := filepath.Dir(os.Args[0])
	t.Logf("Dir=%v", dir)

	path, err = filepath.Abs(dir)
	t.Logf("Abs(Dir)=%v, %+v", path, err)

	path, err = filepath.Abs(filepath.Join(dir, "../../"))
	t.Logf("filepath.Abs(filepath.Join(Dir, \"../../\"))=%v, %+v", path, err)
}
