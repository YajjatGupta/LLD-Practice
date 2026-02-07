#include "DocumentEditor.h"
#include "../core/TextElement.h"
#include "../core/ImageElement.h"


DocumentEditor::DocumentEditor(Document & doc) : document(doc)
{
}

void DocumentEditor::addText(const std::string & text)
{
    document.addElement(std::make_unique<TextElement>(text));
}

void DocumentEditor::addImage(const std::string & path)
{
    document.addElement(std::make_unique<ImageElement>(path));
}
