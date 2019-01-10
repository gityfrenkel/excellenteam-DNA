//
// Created by gity on 1/9/19.
//

#include "PairCommand.h"
#include "../model/DnaSeqPair.h"

int PairCommand::pairRegister = Factory::Register("pair", new PairCommand);

std::string PairCommand::run(std::vector<std::string> commandParams, DnaData* dnadata)
{
    int idSeqInt;
    std::string name;
    std::string sin = commandParams[1].substr(0, 1);
    std::string newName = commandParams[2].substr(0, 2);

    if(sin == "#")
    {
        std::string idSeqStr = commandParams[1].substr(1, commandParams[1].length());
        idSeqInt = atoi(idSeqStr.c_str());
    }
    else 
    {
        if(sin == "@")
        {
            std::string nameSeq = commandParams[1].substr(1, commandParams[1].length());
            //TODO get id by name and idSeqInt = id by name
        }
        else
            return "invalin argument";
    }

    if(newName == "@@")
    {
        name = commandParams[2].substr(3, commandParams[2].length());
    }
    else
    {
        newName = commandParams[2].substr(0, 1);
        if(newName != "@")
            return "invalin argument";

        name = dnadata->getNameById(idSeqInt);
    }

    DnaSeqPair pair(dnadata->getMetadata(idSeqInt)->getDna());
    dnadata->add(idSeqInt, name, pair);
    return dnadata->StrToPrint(name);
}
