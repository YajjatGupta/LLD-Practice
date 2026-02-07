#include "FileStorage.h"
#include <fstream>

void FileStorage::save(const std::string& data) {
    std::ofstream file("document.txt");
    file << data;
    file.close();
}
