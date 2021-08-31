package main

import (
	"net/http"
)

func handleRequest() {
	http.Handle("/", http.FileServer(http.Dir("./html")))
	http.ListenAndServe(":8000", nil)
}

func main() {
	handleRequest()
}
