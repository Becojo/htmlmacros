#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htmlmacros.h"
#include "testhelp.h"

#define assert_str_eq(expected, actual) strcmp(expected, actual) == 0

int main() {
  
  test_cond("element", assert_str_eq(
    element("abc", ""), 
    "<abc></abc>"))
  
  test_cond("element with content", assert_str_eq(
    element("abc", "Hello World!"), 
    "<abc>Hello World!</abc>"))
  
  test_cond("element with attribute", assert_str_eq(
    element("abc", attr("key", "value") , ""), 
    "<abc key=\"value\"></abc>"))
                  
  test_cond("element with attribute and content", assert_str_eq(
    element("abc", attr("key", "value"), "Hello World!"), 
    "<abc key=\"value\">Hello World!</abc>"))
  
  test_cond("self-closing element", assert_str_eq(
    sc_element("br", ""), 
    "<br/>"))

  test_cond("self-closing element and attribute", assert_str_eq(
    sc_element("meta", attr("charset", "UTF-8")),
    "<meta charset=\"UTF-8\"/>"))
   
  test_cond("self-closing element and attributes", assert_str_eq(
    sc_element("link", attr("rel", "stylesheet") 
                       attr("type", "text/css") 
                       attr("href", "style.css")),
    "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"/>"))
  
  test_report()
  
  return 0;
}
