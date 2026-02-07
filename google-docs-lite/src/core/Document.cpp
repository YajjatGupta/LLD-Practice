#include "Document.h"

void Document::addElement(std::unique_ptr<DocumentElement> el) {
    elements.push_back(std::move(el));
}

const std::vector<std::unique_ptr<DocumentElement>>&
Document::getElements() const {
    return elements;
}
