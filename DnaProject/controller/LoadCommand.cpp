//
// Created by gity on 1/2/19.
//

#include "LoadCommand.h"
#include <cstring>

int LoadCommand::loadRegister = Factory::Register("load", new LoadCommand);

std::string LoadCommand::run(std::vector<std::string> commandParams, DnaData* dnadata)
{
    if(commandParams.size() < 2)
    {
        return "You must provide path!!";
    }
    std::string name;
    ReadFile file(commandParams[1].c_str());

    IDnaSequence* dnaSequence = new DnaSequence(file.read());

    SharePointer<IDnaSequence> idnaSequence(dnaSequence);

    if(commandParams.size() > 2 )
    {
        name = commandParams[2];
        if(dnadata->exist(name))
        {
            name = nextSerialName(name, dnadata);
        }
    }
    else
    {
        char *commandStr = strdup(commandParams[1].c_str());
        char *fileName = std::strtok(commandStr, ".");
        name = nextSerialName(fileName, dnadata);
    }

    dnadata->add(++SerialNumber, name, "up to date" ,idnaSequence);


    return dnadata->StrToPrint(name);
}

std::string LoadCommand::nextSerialName(std::string name, DnaData* dnadata)
{
    int SerialNum = 0;
    std::ostringstream oss;
    oss << ++SerialNum;

    std::string nextName = name + "_" + oss.str();
    while(dnadata->exist(nextName))
    {
        std::ostringstream oss;
        oss << ++SerialNum;
        nextName = name + "_" + oss.str();
    }

    return nextName;
}