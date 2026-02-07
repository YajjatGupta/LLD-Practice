#ifndef DOCUMENT_EDITOR_H
#define DOCUMNET_EDITOR_H
#include "../core/Document.h"
#include <string>
class DocumentEditor{
private:
    Document& document;
public:
    DocumentEditor(Document& document);
    void addText(const std::string& text);
    void addImage(const std::string& path);

};
#endif