//
// Created by gity on 1/9/19.
//

#include "DnaSeqPair.h"

DnaSeqPair::DnaSeqPair(SharePointer<IDnaSequence> dna):m_dna(dna)
{}

Nucleotid& DnaSeqPair::operator [](size_t idx)
{
    if (idx > m_dna->get_Length() || idx < 0)
        std::cout << "index out of range";

    return  m_dna->getSequence()[idx];
}

const Nucleotid DnaSeqPair::operator [](size_t idx) const
{
    if (idx > m_dna->get_Length() || idx < 0)
        std::cout << "index out of range";

    return m_dna->getSequence()[idx].getPairNucleotid();
}