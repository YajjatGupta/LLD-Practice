#ifndef DOCUMENT_ELEMENT_H
#define DOCUMENT_ELEMENT_H
class DocumentElement{
public:
    virtual void render() = 0;
    virtual ~DocumentElement() {}
};
#endif
// Abstact Base Class with no data and only behaviour