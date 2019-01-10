//
// Created by gity on 12/30/18.
//

#include "MetaData.h"

MetaData::MetaData(int _id, std::string name, std::string status, SharePointer<IDnaSequence> dna)
{
    m_dnaSequence = dna;
    m_dnaName = name;
    m_status = status;
    m_dnaId = _id;
}

int MetaData::getId()
{
    return m_dnaId;
}

std::string MetaData::getName()
{
    return m_dnaName;
}

SharePointer<IDnaSequence> MetaData::getDna()
{
    return m_dnaSequence;
}

std::string MetaData::getStatus()
{
    return m_status;
}

void MetaData::setStatus(std::string newStatus)
{
    m_status = newStatus;
}