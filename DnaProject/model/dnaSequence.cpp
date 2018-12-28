//
// Created by gity on 12/25/18.
//
#include "dnaSequence.h"
#include <stdio.h>
#include <string.h>

DnaSequence::DnaSequence(char* dnaSequence)
{
    try
    {
        init_DnaSequence(dnaSequence);
    }
    catch (const std::invalid_argument& e)
    {
        delete[] m_dnaSequence;
        throw std::invalid_argument(e.what());
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
        delete[] m_dnaSequence;
        throw std::invalid_argument(e.what());
    }
}

DnaSequence::DnaSequence(const DnaSequence& other)
{
    Nucleotid* tempNucleotid;

    try
    {
        tempNucleotid = new Nucleotid[other.m_length];
    }
    catch (const std::bad_alloc& ba)
    {
        throw std::invalid_argument(ba.what());
    }

    for (size_t i = 0; i < other.m_length; ++i)
    {
        tempNucleotid[i] = other.m_dnaSequence[i];
    }

    m_length = other.m_length;
    m_dnaSequence = tempNucleotid;
}

DnaSequence::~DnaSequence()
{
    delete[] m_dnaSequence;
}

SharePointer<IDnaSequence> DnaSequence::operator=(const std::string& dnaSequenceStr)
{
    try
    {
        return asigmentOp(dnaSequenceStr.c_str());
    }
    catch (const std::invalid_argument& e)
    {
        throw std::invalid_argument(e.what());
    }
}

SharePointer<IDnaSequence> DnaSequence::operator=(const char* dnaSequencechar)
{
    try
    {
        return asigmentOp(dnaSequencechar);
    }
    catch (const std::invalid_argument& e)
    {
        throw std::invalid_argument(e.what());
    }
}

SharePointer<IDnaSequence> DnaSequence::operator=(const SharePointer<IDnaSequence> dnaSequence)
{
//    if ((SharePointer<IDnaSequence>)dnaSequence != (SharePointer<IDnaSequence>&)*this)
//    {
//        delete[] m_dnaSequence;
//        m_length = dnaSequence->get_Length();
//
//        m_dnaSequence = new Nucleotid[m_length];
//
//        for (size_t i = 0; i < m_length; ++i)
//        {
//            m_dnaSequence[i] = dnaSequence.operator->()->operator[](i);
//        }
//
//    }
//    return (SharePointer<IDnaSequence>)this;

    try
    {
        return asigmentOp((const char*)dnaSequence.operator->()->getSequence());
    }
    catch (const std::invalid_argument& e)
    {
        throw std::invalid_argument(e.what());
    }
}

bool DnaSequence::operator==(const SharePointer<IDnaSequence> dnaSequence)const
{
    if(m_length != dnaSequence.operator->()->get_Length())
    {
        return false;
    }

    for (size_t i = 0; i < m_length; ++i)
    {
        if (m_dnaSequence[i] != dnaSequence.operator->()->getSequence()[i])
        {
            return false;
        }
    }
    return true;
}

bool DnaSequence::operator!=(const SharePointer<IDnaSequence> dnaSequence)const
{
    return !(*this == dnaSequence);
}

Nucleotid& DnaSequence::operator [](size_t idx)
{
    if (idx > m_length)
    {
        throw std::invalid_argument("the location is out of range");
    }

    return m_dnaSequence[idx];
}

const Nucleotid& DnaSequence::operator [](size_t idx)const
{
    if (idx > m_length)
    {
        throw std::invalid_argument("the location is out of range");
    }

    return m_dnaSequence[idx];
}

ostream& operator<<(ostream& os, const SharePointer<IDnaSequence> dnaSequence)
{
    for (size_t i = 0; i < dnaSequence.operator->()->get_Length(); ++i)
    {
        os << dnaSequence.operator->()->getSequence()[i];
    }
    return os;
}

size_t DnaSequence::get_Length()const
{
    return m_length;
}

SharePointer<IDnaSequence> DnaSequence::slicing(size_t from, size_t to)
{

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
    catch (const std::bad_alloc& ba)
    {
        throw std::invalid_argument(ba.what());
    }

    for (size_t i = 0; i < m_length; ++i)
    {
        m_dnaSequence[i] = dnasequence[i];
    }

}

SharePointer<IDnaSequence> DnaSequence::asigmentOp(const char* dnasequence)
{
    m_length = strlen(dnasequence);

    if (!validDna(m_length))
    {
        throw std::invalid_argument("the dna length is wrongful");
    }

    delete[] m_dnaSequence;

    try
    {
        m_dnaSequence = new Nucleotid[m_length];
    }
    catch (const std::bad_alloc& ba)
    {
        throw std::invalid_argument(ba.what());
    }

    for (size_t i = 0; i < m_length; ++i)
    {
        m_dnaSequence[i] = dnasequence[i];
    }

    return (SharePointer<IDnaSequence>)this;
}

Nucleotid* DnaSequence::getSequence()
{
    return m_dnaSequence;
}
