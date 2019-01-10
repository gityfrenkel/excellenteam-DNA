//
// Created by gity on 12/29/18.
//

#include "DnaData.h"
#include "../controller/NewCommand.h"
#include <sstream>


void DnaData::add(int _id, std::string name, std::string status, SharePointer<IDnaSequence> dna)
{
    MetaData* metaData = new MetaData(_id, name, status, dna);

    m_mapName.insert(std::pair<std::string, MetaData*>(name, metaData));
    m_mapId.insert(std::pair<int, MetaData*>(_id, metaData));
}

bool DnaData::exist(std::string name)
{
    std::map<std::string, MetaData*>::iterator it;
    it = m_mapName.find(name);

    if(it != m_mapName.end())
        return true;

    return false;
}

std::string DnaData::StrToPrint(std::string name)
{
    int IdByName;

    std::map<std::string, MetaData*>::iterator itNameMap;
    std::map<int, MetaData*>::iterator itIdMap;


    itNameMap = m_mapName.find(name);

    if(itNameMap != m_mapName.end())
    {
        IdByName = itNameMap->second->getId();

        std::string dnaToPrint = "[" + std::to_string(IdByName) + "] ";
        dnaToPrint += name;
        dnaToPrint += ": ";
        std::string dnaByStr = "";

        for( unsigned int i = 0; i < itNameMap->second->getDna()->get_Length(); ++i)
            dnaByStr += itNameMap->second->getDna()->getSequence()[i].getNucleotid();

        if(dnaByStr.length() > 40)
        {
            dnaToPrint += dnaByStr.substr(0, 32);
            dnaToPrint += "...";
            dnaToPrint += dnaByStr.substr(dnaByStr.length()-3, dnaByStr.length());
        }
        else
        {
            dnaToPrint += dnaByStr;
        }

        return dnaToPrint;
    }

    return "";
}

//std::string DnaData::StrToPrint(std::string name)
//{
//    int IdByName;
//
//    std::map<std::string, MetaData*>::iterator itNameMap;
//    std::map<int, MetaData*>::iterator itIdMap;
//
//
//    itNameMap = m_mapName.find(name);
//
//    if(itNameMap != m_mapName.end())
//    {
//        IdByName = itNameMap->second->getId();
//
//        std::ostringstream s;
//
//        s << "[" << IdByName << "] " << name << ": ";
//        s << itIdMap->second->getDna().get();
//        return s.str();
//    }
//
//    return "";
//}

std::string DnaData::getDataStr(int DnaId)
{
    std::map<int, MetaData*>::iterator itIdMap;
    itIdMap = m_mapId.find(DnaId);

    if(itIdMap != m_mapId.end())
    {
        std::string dnaByStr = "";

        for( unsigned int i = 0; i < itIdMap->second->getDna()->get_Length(); ++i)
            dnaByStr += itIdMap->second->getDna()->getSequence()[i].getNucleotid();

        return dnaByStr;
    }
    else
    {
        return "this seq not exist";
    }
}

std::string DnaData::getNameById(int _id)
{
    std::map<int, MetaData*>::iterator itIdMap;
    itIdMap = m_mapId.find(_id);

    if(itIdMap != m_mapId.end())
    {
        return itIdMap->second->getName();
    }
    else
    {
        return "this seq not exist";
    }
}

MetaData* DnaData::getMetadata(int _id)
{
    std::map<int, MetaData*>::iterator itIdMap;
    itIdMap = m_mapId.find(_id);

    if(itIdMap != m_mapId.end())
    {
        return itIdMap->second;
    }
    else
    {
        return NULL;
    }
}

std::map<int, MetaData*>* DnaData::getMap()
{
    return &m_mapId;
}