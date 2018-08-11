package main

import "C"

import (
  "github.com/alecthomas/chroma/quick"
  "bytes"
)

//export FormatCode
func FormatCode(source, language, scheme string) string {
  // Note that the build command is
  // go build -o chroma.so -buildmode=c-shared chroma.go
  buf := new (bytes.Buffer)
  quick.Highlight(buf, source, language, "html", scheme)
  return buf.String()
}

func main() {}
