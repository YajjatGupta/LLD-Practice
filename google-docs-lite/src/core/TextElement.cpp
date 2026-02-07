#include "TextElement.h"
#include <iostream>
TextElement::TextElement(const std::string & t) : text(t){}
void TextElement::render(){
    std::cout<<text<<std::endl;
}