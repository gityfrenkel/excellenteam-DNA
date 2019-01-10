//
// Created by gity on 1/9/19.
//

#ifndef DNAPROJECT_PAIRCOMMAND_H
#define DNAPROJECT_PAIRCOMMAND_H

#include "Icommand.h"

class PairCommand : public Icommand
{
public:
    std::string run(std::vector<std::string> commandParams, DnaData* dnadata);

private:
    static int pairRegister;
};


#endif //DNAPROJECT_PAIRCOMMAND_H
