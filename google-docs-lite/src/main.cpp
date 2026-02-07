#include<iostream>
#include"core/Document.h"
#include"editor/DocumentEditor.h"
#include"render/DocumentRenderer.h"
int main(){
    Document document;
    DocumentEditor editor(document);
    DocumentRenderer renderer;
    editor.addText("Hello Google Docs Lite");
    editor.addImage("photo.png");
    renderer.render(document);
}