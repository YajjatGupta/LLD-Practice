#include "ImageElement.h"
#include <iostream>
ImageElement::ImageElement(const std::string& p) : path(p){}
void ImageElement::render(){
    std::cout<<"[Image: "<< path<<"]"<<std::endl;
}
