package api

import (
	"fmt"
	"html/template"
	"net/http"
	"time"
	"web/session"
	"web/utils"
)

func HandleCount(w http.ResponseWriter, r *http.Request) {
	s := session.GSessionManager.SessionStart(w, r)
	ct := s.Get("createTime")
	if ct == nil {
		ct = time.Now().Unix()
		s.Set("createTime", ct)
	} else if time.Now().Unix() > (ct.(int64) + 60) {
		session.GSessionManager.SessionDestroy(w, r)
		session.GSessionManager.SessionStart(w, r)
	}

	if num := s.Get("num"); num == nil {
		s.Set("num", 1)
	} else {
		s.Set("num", (num.(int) + 1))
	}

	t, err := template.ParseFiles("template/count.gtpl")
	if err != nil {
		utils.WriteReq(w, r)
		fmt.Fprintln(w, template.HTMLEscapeString(err.Error()))
		return
	}

	w.Header().Set("Content-Type", "text/html")
	t.Execute(w, &struct {
		Num         int
		CreatedTime string
	}{
		Num:         s.Get("num").(int),
		CreatedTime: time.Unix(ct.(int64), 0).String(),
	})
}
