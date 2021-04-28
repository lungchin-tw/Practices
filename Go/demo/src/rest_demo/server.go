package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/julienschmidt/httprouter"
)

func Index(w http.ResponseWriter, r *http.Request, params httprouter.Params) {
	fmt.Println("Index")
	fmt.Fprint(w, "Welcome!")
}

func Hello(w http.ResponseWriter, r *http.Request, params httprouter.Params) {
	name := params.ByName("name")
	fmt.Println("Hello:", name)
	fmt.Fprintf(w, "Hello, %v!", name)
}

func addUser(w http.ResponseWriter, r *http.Request, params httprouter.Params) {
	uid := params.ByName("uid")
	fmt.Println("addUser:", uid)
	fmt.Fprintf(w, "New User: %v.", uid)
}

func delUser(w http.ResponseWriter, r *http.Request, params httprouter.Params) {
	uid := params.ByName("uid")
	fmt.Println("delUser:", uid)
	fmt.Fprintf(w, "Deleted User: %v.", uid)
}

func modifyUser(w http.ResponseWriter, r *http.Request, params httprouter.Params) {
	uid := params.ByName("uid")
	fmt.Println("modifyUser:", uid)
	fmt.Fprintf(w, "Modify User: %v.", uid)
}

func main() {
	router := httprouter.New()
	router.GET("/", Index)
	router.GET("/hello/:name", Hello)

	router.POST("/user/:uid", addUser)
	router.DELETE("/user/:uid", delUser)
	router.PUT("/user/:uid", modifyUser)

	fmt.Println("Server Startup")
	log.Fatal(http.ListenAndServe(":8080", router))
}
