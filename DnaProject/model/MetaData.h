//
// Created by gity on 12/30/18.
//

#ifndef DNAPROJECT_METADATA_H
#define DNAPROJECT_METADATA_H
#include "IDnaSequence.h"
#include "Shared_pointer.h"


class MetaData
{
public:
    MetaData(int _id, std::string, SharePointer<IDnaSequence>);
    int getId();
    std::string getName();
    SharePointer<IDnaSequence> getDna();

private:
    int m_dnaId;
    std::string m_dnaName;
    SharePointer<IDnaSequence> m_dnaSequence;
};


#endif //DNAPROJECT_METADATA_H
