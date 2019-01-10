//
// Created by gity on 1/2/19.
//

#ifndef DNAPROJECT_LOADCOMMAND_H
#define DNAPROJECT_LOADCOMMAND_H

#include "Icommand.h"
#include "../model/ReadFile.h"

class LoadCommand : public Icommand
{
public:
    std::string run(std::vector<std::string> commandParams, DnaData* dnadata);
    std::string nextSerialName(std::string name, DnaData* dnadata);

private:
    static int loadRegister;
};


#endif //DNAPROJECT_LOADCOMMAND_H
