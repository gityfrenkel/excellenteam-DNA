//
// Created by gity on 1/5/19.
//

#ifndef DNAPROJECT_SHOWCOMMAND_H
#define DNAPROJECT_SHOWCOMMAND_H

#include "Icommand.h"

class ShowCommand : public Icommand
{
public:
    std::string run(std::vector<std::string> commandParams, DnaData* dnadata);
    std::string show(int _id, size_t numChars, DnaData* dnaData);

private:
    static int showRegister;
};


#endif //DNAPROJECT_SHOWCOMMAND_H
