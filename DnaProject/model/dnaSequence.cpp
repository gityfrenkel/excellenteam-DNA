//
// Created by gity on 12/25/18.
//
#include "dnaSequence.h"
#include <stdio.h>
#include <string.h>

DnaSequence::DnaSequence(const char* dnaSequence)
{
    try
    {
        init_DnaSequence(dnaSequence);
    }
    catch (const std::bad_alloc)
    {
        throw std::bad_alloc();
    }
    catch (const std::invalid_argument& e)
    {
        throw std::invalid_argument(e);
    }

}

DnaSequence::DnaSequence(std::string& dnaSequenceStr)
{
    try
    {
        init_DnaSequence(dnaSequenceStr.c_str());
    }
    catch (const std::invalid_argument& e)
    {
        throw std::invalid_argument(e.what());
    }
    catch (const std::bad_alloc)
    {
        throw std::bad_alloc();
    }
}

DnaSequence::~DnaSequence()
{

    delete[] m_dnaSequence;
}

IDnaSequence* DnaSequence::operator=(const std::string& dnaSequenceStr)
{
    try
    {
        return asigmentOp(dnaSequenceStr.c_str());
    }
    catch (const std::bad_alloc)
    {
        throw std::bad_alloc();
    }
}

IDnaSequence* DnaSequence::operator=(const char* dnaSequencechar)
{
    try
    {
        return asigmentOp(dnaSequencechar);
    }
    catch (const std::bad_alloc)
    {
        throw std::bad_alloc();
    }
}

bool DnaSequence::operator==(const IDnaSequence* dnaSequence) const
{
    if(m_length != dnaSequence->get_Length())
    {
        return false;
    }

    for (size_t i = 0; i < m_length; ++i)
    {
        if (m_dnaSequence[i] != (*dnaSequence)[i])
        {
            return false;
        }
    }
    return true;
}

bool DnaSequence::operator!=(const IDnaSequence* dnaSequence) const
{
    return !(*this == dnaSequence);
}

Nucleotid& DnaSequence::operator [](size_t idx)
{
    if (idx > m_length || idx < 0)
    {
        throw std::invalid_argument(" index out of range");
    }

    return m_dnaSequence[idx];
}

const Nucleotid DnaSequence::operator [](size_t idx) const
{
    if (idx > m_length || idx < 0)
    {
        throw std::invalid_argument("index out of range");
    }

    return m_dnaSequence[idx];
}

ostream& operator<<(ostream& os, const DnaSequence dnaSequence)
{
    for (size_t i = 0; i < dnaSequence.get_Length(); ++i)
    {
        os << dnaSequence.getSequence()[i];
    }
    return os;
}

std::ostringstream& operator<< (std::ostringstream &os, const IDnaSequence* idnaSequence)
{
    size_t len = idnaSequence->get_Length();

    for (size_t i = 0; i < len; ++i)
    {
        os << idnaSequence->getSequence()[i].getNucleotid();
    }

    return os;
}

size_t DnaSequence::get_Length() const
{
    return m_length;
}

void DnaSequence::init_DnaSequence(const char* dnasequence)
{
    m_length = strlen(dnasequence);
    if (!validDna(m_length))
    {
        throw std::invalid_argument("the dna length is wrongful");
    }

    try
    {
        m_dnaSequence = new Nucleotid[m_length];
    }
    catch (const std::bad_alloc)
    {
        throw std::bad_alloc();
    }

    for (size_t i = 0; i < m_length; ++i)
    {
        m_dnaSequence[i] = dnasequence[i];
    }

}

IDnaSequence* DnaSequence::asigmentOp(const char* dnasequence)
{
    if (!validDna(strlen(dnasequence)))
    {
        throw std::invalid_argument("the dna length is wrongful");
    }


    delete[] m_dnaSequence;

    try
    {
        m_dnaSequence = new Nucleotid[strlen(dnasequence)];
    }
    catch (const std::bad_alloc)
    {
        throw std::bad_alloc();
    }

    m_length = strlen(dnasequence);
    for (size_t i = 0; i < m_length - 1; ++i)
    {
        m_dnaSequence[i] = dnasequence[i];
    }

    return this;
}

Nucleotid* DnaSequence::getSequence() const
{
    return m_dnaSequence;
}

//std::string DnaSequence::getSeqStr()
//{
//    std::string dnaStr = "";
//
//    for( unsigned int i = 0; i < m_length; ++i)
//        dnaStr += m_dnaSequence[i].getNucleotid();
//
//    return dnaStr;
//}
