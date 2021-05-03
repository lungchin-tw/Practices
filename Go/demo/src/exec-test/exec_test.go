package test

import (
	"os"
	"os/exec"
	"testing"
)

func TestExec01(t *testing.T) {
	t.Log(exec.LookPath("go"))
	t.Log(exec.LookPath("bash"))
}

func TestExec02(t *testing.T) {
	path, err := exec.LookPath("svn")
	if err != nil {
		t.Fatal(err)
	} else {
		t.Log(path)
	}

	cmd := &exec.Cmd{
		Path:   path,
		Args:   []string{"svn", "cleanup", "/Users/jacky/Documents/svn/hdtclient"},
		Stdin:  os.Stdin,
		Stdout: os.Stdout,
		Stderr: os.Stderr,
	}

	cmd.Start()
	t.Log("Command is Executing...")
	cmd.Wait()
	t.Log("Finished Command Executing.")

	cmd = &exec.Cmd{
		Path:   path,
		Args:   []string{"svn", "update", "/Users/jacky/Documents/svn/hdtclient"},
		Stdin:  os.Stdin,
		Stdout: os.Stdout,
		Stderr: os.Stderr,
	}
	cmd.Start()
	t.Log("Command is Executing...")
	cmd.Wait()
	t.Log("Finished Command Executing.")
}

func TestExec03(t *testing.T) {
	path, err := exec.LookPath("svn")
	if err != nil {
		t.Fatal(err)
	} else {
		t.Log(path)
	}

	cmd := &exec.Cmd{
		Path:   path,
		Args:   []string{"svn", "update", "/Users/jacky/Documents/svn/hdtclient"},
		Stdin:  os.Stdin,
		Stdout: os.Stdout,
		Stderr: os.Stderr,
	}

	cmd.Start()
	t.Log("Command is Executing...")
	cmd.Wait()
	t.Log("Finished Command Executing.")
}

func TestExec04(t *testing.T) {
	cmd := &exec.Cmd{
		Path:   "./exec_test.sh",
		Args:   []string{"./exec_test.sh"},
		Stdin:  os.Stdin,
		Stdout: os.Stdout,
		Stderr: os.Stderr,
	}

	cmd.Start()
	t.Log("Command is Executing...")
	cmd.Wait()
	t.Log("Finished Command Executing.")
}
