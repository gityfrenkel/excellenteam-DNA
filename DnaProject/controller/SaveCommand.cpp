//
// Created by gity on 1/3/19.
//

#include "SaveCommand.h"
#include <cstdlib>
#include "../model/WriteFile.h"

int SaveCommand::saveRegister = Factory::Register("save", new SaveCommand);

std::string SaveCommand::run(std::vector<std::string> commandParams, DnaData* dnadata)
{
    if(commandParams.size() < 2)
    {
        return "You must provide seq!!";
    }

    std::string idSeqStr = commandParams[1].substr(1, commandParams[1].length());
    int idSeqInt = atoi(idSeqStr.c_str());

    std::string dnaStr = dnadata->getDataStr(idSeqInt);
    DnaSequence dna(dnaStr);

    std::string fileName;
    if(commandParams.size() > 2)
    {
        fileName = commandParams[2];
    }
    else
    {
        fileName = dnadata->getNameById(idSeqInt);
    }

    fileName += ".rawdna";

    WriteFile newFile(fileName.c_str());
    newFile.write(dna);

    dnadata->getMetadata(idSeqInt)->setStatus("saved");

    return "saved";
}