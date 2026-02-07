#ifndef FILE_STORAGE_H
#define FILE_STORAGE_H

#include "Persistence.h"

class FileStorage : public Persistence {
public:
    void save(const std::string& data) override;
};

#endif
