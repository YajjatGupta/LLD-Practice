#ifndef IMAGE_EDITOR_H
#define IMAGE_EDITOR_H
#include "DocumentElement.h"
#include <string>
class ImageElement : public DocumentElement{
private:
    std::string path;
public:
    ImageElement(const std::string& p);
    void render() override;
};
#endif