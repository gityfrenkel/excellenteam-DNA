//
// Created by gity on 1/3/19.
//

#ifndef DNAPROJECT_SAVECOMMAND_H
#define DNAPROJECT_SAVECOMMAND_H

#include "Icommand.h"

class SaveCommand : public Icommand
{
public:
    std::string run(std::vector<std::string> commandParams, DnaData* dnadata);

private:
    static int saveRegister;
};


#endif //DNAPROJECT_SAVECOMMAND_H
