//
// Created by gity on 12/29/18.
//
#include "DnaData.h"

void DnaData::add(char* seqName, int seqId, SharePointer<IDnaSequence> mySeq)//TODO must return it's only to can run
{
    DnaDetails addVar;
    addVar.dnaSeq = mySeq;
    addVar.SeqId = seqId;
    addVar.SeqName = seqName;

    m_dataVector.push_back(addVar);
}

DnaDetails* DnaData::getDnaArray()//TODO must return it's only to can run
{
    return &m_dataVector.back();
}

void DnaData::del(char* seqName, int seqId)//TODO must return it's only to can run
{
    m_dataVector.clear();
}