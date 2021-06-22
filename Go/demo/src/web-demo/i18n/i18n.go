package i18n

import (
	"examples/web-demo/utils"
	"fmt"
	"net/http"
	"time"
)

func HandleI18N(w http.ResponseWriter, r *http.Request) {
	fmt.Println(utils.CurLineDesc())
	r.ParseForm() // parse arguments, you have to call this by yourself

	fmt.Println("HEADER:")
	for key, value := range r.Header {
		fmt.Println("KEY VALUE:", key, value)
	}

	utils.WriteReq(w, r)

	fmt.Println("Accept-Language:", r.Header.Get("Accept-Language"))

	if locale := r.URL.Path[len("/i18n/"):]; locale == "en" {
		handleEN(w, r)
	} else if locale == "tw" {
		handleTW(w, r)
	}
}

func handleTW(w http.ResponseWriter, r *http.Request) {
	fmt.Println(utils.CurLineDesc())
	r.ParseForm() // parse arguments, you have to call this by yourself

	loc, err := time.LoadLocation("Asia/Taipei")
	fmt.Printf("time.LoadLocation: %v, Error:%v\n", loc, err)

	fmt.Println("TimestampUTC:", time.Now().UTC().Format(time.RFC850))

	now := time.Now().In(loc)
	timedesc := now.Format(time.RFC850)
	fmt.Println("Timestamp:", timedesc)
	fmt.Fprintln(w, "Timestamp: ", timedesc)

	datedesc := formateDate("%v年%d月%v日 %v時%v分%v秒", now)
	fmt.Println("Date:", datedesc)
	fmt.Fprintln(w, "Date: ", datedesc)
}

func handleEN(w http.ResponseWriter, r *http.Request) {
	fmt.Println(utils.CurLineDesc())
	r.ParseForm() // parse arguments, you have to call this by yourself

	loc, err := time.LoadLocation("Asia/Taipei")
	fmt.Printf("time.LoadLocation: %v, Error:%v\n", loc, err)
	now := time.Now().In(loc)
	timedesc := now.Format(time.RFC850)
	fmt.Println("Timestamp:", timedesc)
	fmt.Fprintln(w, "Timestamp: ", timedesc)

	datedesc := formateDate("%v-%d-%v %v:%v:%v", now)
	fmt.Println("Date:", datedesc)
	fmt.Fprintln(w, "Date: ", datedesc)
}

func formateDate(format string, t time.Time) string {
	year, month, day := t.Date()
	hour, min, sec := t.Clock()
	return fmt.Sprintf(format, year, month, day, hour, min, sec)
}
