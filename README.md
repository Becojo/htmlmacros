# htmlmacros

A handful bunch of macros for C/C++ to create HTML from literal strings 

## Features

* **Super compact**!! no spaces between elements WOW
* **Lightning fast**!!1! no parsing or complex templating systems. 
* Does absolutely not **work** with anything other than literal C-string

## Examples

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

Outputs (prettified for readability): 

    <!doctype html>
    <html>
      <head>
        <meta charset="UTF-8"/>
        <title>
          Hello World
        </title>
      </head>
      <body>
        <h1>Lorem Ipsum</h1>
        <p>Hello <span class="important">world</span></p>
        <blockquote>This is <em>madness</em></blockquote>
      </body>
    </html>

## Tests
    
Tests are made using `testhelp.h` from [antirez/sds](https://github.com/antirez/sds).

    make test && ./test
    
## License

  Public domain
