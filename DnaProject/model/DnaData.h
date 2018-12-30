//
// Created by gity on 12/29/18.
//

#ifndef DNAPROJECT_DNADATA_H
#define DNAPROJECT_DNADATA_H
#include <vector>
#include "IDnaSequence.h"
#include "Shared_pointer.h"

typedef struct DnaDetails{

    char* SeqName;
    int SeqId = 0;
    SharePointer<IDnaSequence> dnaSeq;

} DnaDetails;

class DnaData
{
public:
    DnaData(){}
    void add(char*, int, SharePointer<IDnaSequence>);
    DnaDetails* getDnaArray();
    void del(char*, int = 0);

private:
    std::vector<DnaDetails> m_dataVector;
};




#endif //DNAPROJECT_DNADATA_H
