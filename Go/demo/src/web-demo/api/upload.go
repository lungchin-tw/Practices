package api

import (
	"examples/web-demo/utils"
	"fmt"
	"html/template"
	"io"
	"net/http"
	"os"
	"path/filepath"
)

func HandleUpload(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		t, err := template.ParseFiles("template/upload.gtpl")
		if err != nil {
			utils.ProcessRequestException(err, w, r)
		} else if err := t.Execute(w, utils.GenToken()); err != nil {
			utils.ProcessRequestException(err, w, r)
		}
	} else if r.Method == "POST" {
		r.ParseMultipartForm(32 << 20)
		uf, fh, err := r.FormFile("uploadfile")
		if err != nil {
			utils.ProcessRequestException(err, w, r)
			return
		}

		defer uf.Close()

		fmt.Println("FileHeader.Filename:", fh.Filename)
		fmt.Println("FileHeader.Header:", fh.Header)
		fmt.Println("FileHeader.Size:", fh.Size)
		fmt.Fprintf(w, "%v", fh.Header)

		f, err := os.OpenFile(filepath.Join("./upload", fh.Filename), os.O_WRONLY|os.O_CREATE, 0666)
		if err != nil {
			utils.ProcessRequestException(err, w, r)
			return
		}

		defer f.Close()
		written, err := io.Copy(f, uf)
		fmt.Println("io.Copy:", written, err)
	} else {
		err := fmt.Errorf("Invalid Method:%v", r.Method)
		fmt.Fprintln(w, template.HTMLEscapeString(err.Error()))
	}
}
