package main

import "C"

import (
  "github.com/alecthomas/chroma/quick"
  "github.com/alecthomas/chroma/lexers"
  "github.com/alecthomas/chroma/styles"
  "github.com/alecthomas/chroma/formatters/html"
  "bytes"
)

//export FormatCode
func FormatCode(source_, language_, scheme_ *C.char) *C.char{
  // Note that the build command is
  // go build -o chroma.so -buildmode=c-shared chroma.go
  source := C.GoString(source_)
  language := C.GoString(language_)
  scheme := C.GoString(scheme_)

  buf := new (bytes.Buffer)
  quick.Highlight(buf, source, language, "html", scheme)
  return C.CString(buf.String())
}

//export FormatCodeWithoutInlineCss
func FormatCodeWithoutInlineCss(source_, language_, scheme_ *C.char) *C.char {
  source := C.GoString(source_)
  language := C.GoString(language_)
  scheme := C.GoString(scheme_)

  lexer := lexers.Get(language)
  if lexer == nil {
    lexer = lexers.Fallback
  }
  style := styles.Get(scheme)
  if style == nil {
    style = styles.Fallback
  }
  formatter := html.New(html.WithClasses())
  iterator, _ := lexer.Tokenise(nil, source)

  buf := new (bytes.Buffer)
  formatter.Format(buf, style, iterator)
  return C.CString(buf.String())
}

//export GetChromaCss
func GetChromaCss(scheme_ *C.char) *C.char {
  scheme := C.GoString(scheme_)
  style := styles.Get(scheme)
  if style == nil {
    style = styles.Fallback
  }
  formatter := html.New(html.WithClasses())
  buf := new (bytes.Buffer)
  formatter.WriteCSS(buf, style)
  return C.CString(buf.String())
}

func main() {}
