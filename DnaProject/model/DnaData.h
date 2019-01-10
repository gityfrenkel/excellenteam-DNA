//
// Created by gity on 12/29/18.
//

#ifndef DNAPROJECT_DNADATA_H
#define DNAPROJECT_DNADATA_H
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <cstddef>
#include "MetaData.h"

class DnaData
{
public:
    DnaData(){}

    void add(int _id, std::string name, std::string status, SharePointer<IDnaSequence> dna);
    bool exist(std::string name);
    std::string StrToPrint(std::string name);
    std::string getDataStr(int DnaId);
    std::string getNameById(int _id);
    MetaData* getMetadata(int _id);
    std::map<int, MetaData*>* getMap();

private:
    std::map<std::string, MetaData*> m_mapName;
    std::map<int, MetaData*> m_mapId;
};




#endif //DNAPROJECT_DNADATA_H
