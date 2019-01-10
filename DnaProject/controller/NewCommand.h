//
// Created by gity on 12/30/18.
//

#ifndef DNAPROJECT_NEWCOMMAND_H
#define DNAPROJECT_NEWCOMMAND_H

#include "Icommand.h"
#include <iostream>
#include <sstream>

class NewCommand : public Icommand
{
public:
    std::string run(std::vector<std::string> commandParams, DnaData* dnadata);
    std::string nextSerialName(DnaData* dnaData);

    static int SerialNameNumber;
private:
    static int newRegister;

};



#endif //DNAPROJECT_NEWCOMMAND_H
