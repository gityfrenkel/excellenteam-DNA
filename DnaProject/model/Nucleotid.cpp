//
// Created by gity on 12/25/18.
//
#include "Nucleotid.h"
#include <assert.h>
using std::ostream;

Nucleotid& Nucleotid::operator=(char nucleotid)
{
    try
    {
        m_nucleotid = validNucleotid(nucleotid);
    }
    catch(std::invalid_argument& e)
    {
        throw std::invalid_argument(e.what());
    }
    return *this;
}

Nucleotid& Nucleotid::operator=(const Nucleotid& nucleotid)
{
    m_nucleotid = nucleotid.m_nucleotid;
    return *this;
}

Nucleotid Nucleotid::getPairNucleotid() const
{
    char compliment;
    switch (m_nucleotid) {
        case 'A':
            compliment = 'T';
            break;
        case 'C':
            compliment = 'G';
            break;
        case 'G':
            compliment = 'C';
            break;
        case 'T':
            compliment = 'A';
        default:
            assert(m_nucleotid);
    }
    return Nucleotid(compliment);
}

char Nucleotid::getNucleotid() const
{
    return m_nucleotid;
}

ostream& operator<<(ostream& os, const Nucleotid& nucleotid)
{
    os << nucleotid.m_nucleotid;
    return os;
}

bool Nucleotid::operator==(const Nucleotid& nucleotid)const
{
    return m_nucleotid == nucleotid.m_nucleotid;
}

bool Nucleotid::operator!=(const Nucleotid& nucleotid)const
{
    return m_nucleotid != nucleotid.m_nucleotid;
}