//
// Created by gity on 12/30/18.
//

#ifndef DNAPROJECT_ICOMMAND_H
#define DNAPROJECT_ICOMMAND_H

#include <vector>
#include "../model/DnaData.h"
#include "Factory.h"

class Icommand
{
public:
    virtual std::string run(std::vector<std::string> commandParams, DnaData* dnadata) = 0;
    static int SerialNumber;
};


#endif //DNAPROJECT_ICOMMAND_H
