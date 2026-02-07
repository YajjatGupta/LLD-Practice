#include "DocumentRenderer.h"

void DocumentRenderer::render(const Document & doc)
{
    for (const auto& el : doc.getElements()){
        el->render();
    }
}