#include <fstream>
#include "../header/header.h"
#define pb push_back
void SequentialFile::setPath(std::string file_path) {
    _file_path = file_path;
}

void SequentialFile::setDelimiter(char delimiter) {
    _delimiter = delimiter;
}

void SequentialFile::set(std::string file_path, char delimiter) {
    _file_path = file_path;
    _delimiter = delimiter;
}

SequentialFile::SequentialFile(std::string file_path, char delimiter) {
    set(file_path, delimiter);
}

void SequentialFile::read() {
    std::ifstream file(_file_path);
    std::string unit;
    char c;
    size_t len;
    std::vector<std::string> _temp_data;
    while(!file.eof()) {
        len = 0;
        do {
            file.get(c);
            unit = unit + c;
            len++;
        } while(!file.eof() && c != _delimiter);
        _temp_data.pb(unit.substr(0, len - 1));
    }
    file.close();

    _file_data = _temp_data;
}

void SequentialFile::write() {
    std::ofstream file(_file_path);
    for(std::string _data : _file_data) file << _data << _delimiter;
    file.close();
}

std::string SequentialFile::getPath() {
    return _file_path;
}

std::vector<std::string> SequentialFile::getAll() {
    return _file_data;
}

std::string SequentialFile::getData(unsigned long index) {
    return _file_data[index];
}

size_t SequentialFile::getTotalUnits() {
    return _file_data.size();
}

bool SequentialFile::compare(SequentialFile &compFile) {
    unsigned long sizeFile = getTotalUnits(), sizeCompFile = compFile.getTotalUnits();
    unsigned long minSize = (sizeFile < sizeCompFile ? sizeFile : sizeCompFile);
    unsigned long maxSize = (sizeFile > sizeCompFile ? sizeFile : sizeCompFile);

    unsigned long itr = 0;
    unsigned long comp = 0;
    while(comp == 0 && itr < minSize) {
        comp = _file_data[itr].compare(compFile._file_data[itr]);
        itr++;
    }
    if(itr < maxSize) comp = -1;
    
    return (comp == 0 ? 1 : 0);
}

#undef pb