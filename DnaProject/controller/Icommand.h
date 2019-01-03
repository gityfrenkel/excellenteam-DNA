//
// Created by gity on 12/30/18.
//

#ifndef DNAPROJECT_ICOMMAND_H
#define DNAPROJECT_ICOMMAND_H

#include <vector>
#include "../model/DnaData.h"

class Icommand
{
public:
    virtual void run(std::vector<std::string> commandParams, DnaData* dnadata) = 0;
    static int SerialNumber;
};


#endif //DNAPROJECT_ICOMMAND_H
