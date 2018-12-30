//
// Created by gity on 12/29/18.
//

#ifndef DNAPROJECT_READFILE_H
#define DNAPROJECT_READFILE_H

#include "dnaSequence.h"

class ReadFile
{
public:
    ReadFile(const char * path);
    ReadFile(ReadFile const & other);
    ~ReadFile();
    DnaSequence read();
private:
    std::string m_fileData;
};


#endif //DNAPROJECT_READFILE_H
