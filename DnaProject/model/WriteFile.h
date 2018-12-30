//
// Created by gity on 12/29/18.
//

#ifndef DNAPROJECT_WRITEFILE_H
#define DNAPROJECT_WRITEFILE_H

#include "dnaSequence.h"

class WriteFile
{
public:
    WriteFile(const char * path);
    WriteFile(WriteFile const & other);

    ~WriteFile();

    void write(const DnaSequence);
private:
    std::string m_fileName;
};


#endif //DNAPROJECT_WRITEFILE_H
