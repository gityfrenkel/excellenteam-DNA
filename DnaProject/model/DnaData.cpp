//
// Created by gity on 12/29/18.
//

#include "DnaData.h"
#include "../controller/NewCommand.h"


void DnaData::add(int _id, std::string name, SharePointer<IDnaSequence> dna)
{
    MetaData metaData(_id, name, dna);

    m_mapName.insert(std::pair<std::string, MetaData>(metaData.getName(), metaData));
    m_mapId.insert(std::pair<int, MetaData>(metaData.getId(), metaData));
}

bool DnaData::exist(std::string name)
{
    std::map<std::string, MetaData>::iterator it;
    it = m_mapName.find(name);

    if(it != m_mapName.end())
        return true;

    return false;
}

std::string DnaData::StrToPrint(std::string name)
{
    int IdByName;

    std::map<std::string, MetaData>::iterator itNameMap;
    std::map<int, MetaData>::iterator itIdMap;


    itNameMap = m_mapName.find(name);

    if(itNameMap != m_mapName.end())
    {
        IdByName = itNameMap.operator->()->second.getId();

        std::string dnaToPrint = "[" + std::to_string(IdByName) + "] ";
        dnaToPrint += name;
        dnaToPrint += ": ";
        std::string dnaByStr = itNameMap.operator->()->second.getDna().operator->()->getSeqStr();
        if(dnaByStr.length() > 40)
        {
            dnaToPrint += dnaByStr.substr(0, 32);
            dnaToPrint += "...";
            dnaToPrint += dnaByStr.substr(dnaByStr.length()-3, dnaByStr.length());
        }

        return dnaToPrint;
    }

    return "";
}



