#ifndef TEXT_ELEMENT_H
#define TEXT_ELEMENT_H
#include "DocumentElement.h"
#include <string>
class TextElement : public DocumentElement{
private:
    std::string text;
public:
    TextElement(const std::string& t);
    void render() override;
};
#endif