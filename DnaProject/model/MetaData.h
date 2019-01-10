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
    MetaData(int _id, std::string, std::string, SharePointer<IDnaSequence>);
    int getId();
    std::string getName();
    SharePointer<IDnaSequence> getDna();
    std::string getStatus();
    void setStatus(std::string newStatus);

private:
    int m_dnaId;
    std::string m_dnaName;
    SharePointer<IDnaSequence> m_dnaSequence;
    std::string m_status;
};


#endif //DNAPROJECT_METADATA_H
