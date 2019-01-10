//
// Created by gity on 1/6/19.
//

#ifndef DNAPROJECT_LISTCOMMAND_H
#define DNAPROJECT_LISTCOMMAND_H

#include "Icommand.h"

class ListCommand : public Icommand
{
public:
    std::string run(std::vector<std::string> commandParams, DnaData* dnadata);

private:
    static int listRegister;
};

#endif //DNAPROJECT_LISTCOMMAND_H
