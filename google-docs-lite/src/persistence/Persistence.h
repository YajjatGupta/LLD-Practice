#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <string>

class Persistence {
public:
    virtual void save(const std::string& data) = 0;
    virtual ~Persistence() {}
};

#endif
