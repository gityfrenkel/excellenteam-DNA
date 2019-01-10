//
// Created by gity on 1/9/19.
//

#ifndef DNAPROJECT_DNASEQPAIR_H
#define DNAPROJECT_DNASEQPAIR_H

#include "IDnaSequence.h"
#include "Shared_pointer.h"

class DnaSeqPair : public IDnaSequence
{
public:
    DnaSeqPair(SharePointer<IDnaSequence> dna);
    size_t get_Length() const { return m_dna->get_Length();}
    Nucleotid& operator [](size_t idx);
    const Nucleotid operator [](size_t idx) const;

private:
    SharePointer<IDnaSequence> m_dna;
};


#endif //DNAPROJECT_DNASEQPAIR_H
