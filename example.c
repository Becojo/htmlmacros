// imports the macros
#include <stdio.h>
#include "htmlmacros.h"

int main() {
  char *out = doctype() html(
    head(
      meta(attr("charset", "UTF-8"))
      title("Hello World"))

    body(
      h1("Lorem Ipsum")
      p("Hello " span(attr("class", "important"), "world"))
      blockquote("This is " em("madness"))));

  puts(out);

  return 0;
}
