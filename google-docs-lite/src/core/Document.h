#ifndef DOCUMENT_H
#define DOCUMENT_H
#include<vector>
#include<memory>
#include "DocumentElement.h"
class Document {
private:
    std::vector<std::unique_ptr<DocumentElement>> elements;
public:
    void addElement(std::unique_ptr<DocumentElement> el);
    const std::vector<std::unique_ptr<DocumentElement>>& getElements() const;
};
#endif