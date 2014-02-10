#ifndef HTMLMACROS_H
#define HTMLMACROS_H

// Google: "c macros overloading", first link, Stackoverflow
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME 

#define element3(name, attributes, content) "<" name attributes ">" content "</" name ">"
#define element2(name, content) element3(name, "", content)

// element with content and optionally attributes
#define element(...) GET_MACRO(__VA_ARGS__, element3, element2)(__VA_ARGS__)

// self-closing element with attributes
#define sc_element(name, attributes) "<" name attributes "/>"

// element attribute
#define attr(key, value) " " key "=\"" value "\""

// HTML5 doctype
#define doctype()         "<!doctype html>" 
#define html(content)     element2("html", content) 

  #define head(content)     element2("head", content)   
    #define meta(attr)        sc_element("meta", attr)
    #define link(attr)        sc_element("link", attr)
    #define title(name)       element2("title", name)
                              
    #define style(...)        element("style", ##__VA_ARGS__)
    #define script(...)       element("script", ##__VA_ARGS__)
    
  #define body(content)     element2("body", content) 
    #define h1(...)           element("h1", ##__VA_ARGS__)
    #define h2(...)           element("h2", ##__VA_ARGS__)
    #define h3(...)           element("h3", ##__VA_ARGS__)
    #define h4(...)           element("h4", ##__VA_ARGS__)
    #define h5(...)           element("h5", ##__VA_ARGS__)
    #define h6(...)           element("h6", ##__VA_ARGS__)
                              
    #define div(...)          element("div", ##__VA_ARGS__)
    #define span(...)         element("span", ##__VA_ARGS__)
    #define p(...)            element("p", ##__VA_ARGS__)
    #define em(...)           element("em", ##__VA_ARGS__)
    #define pre(...)          element("pre", ##__VA_ARGS__)
    #define blockquote(...)   element("blockquote", ##__VA_ARGS__)
    #define a(...)            element("a", ##__VA_ARGS__)
    #define ul(...)           element("ul", ##__VA_ARGS__)
    #define ol(...)           element("ol", ##__VA_ARGS__)
    #define li(...)           element("li", ##__VA_ARGS__)
    #define img(attr)         sc_element("img", attr)
    #define br()              sc_element("br", "")
    #define hr()              sc_element("hr", "")
                              
    #define header(...)       element("header", ##__VA_ARGS__)
    #define section(...)      element("section", ##__VA_ARGS__)
    #define nav(...)          element("nav", ##__VA_ARGS__)
    #define article(...)      element("article", ##__VA_ARGS__)
    #define footer(...)       element("footer", ##__VA_ARGS__)
    
    #define form(...)         element("form", ##__VA_ARGS__)
    #define input(attr)       sc_element("input", attr)
    #define button(...)       element("button", ##__VA_ARGS__)
    #define select(...)       element("select", ##__VA_ARGS__)
    #define option(...)       element("option", ##__VA_ARGS__)
    #define textarea(...)     element("textarea", ##__VA_ARGS__)
    
// helper to generate basic html document
#define html_bootstrap(h, b) doctype() html(head(meta(attr("charset", "UTF-8")) h) body(b))

#endif
