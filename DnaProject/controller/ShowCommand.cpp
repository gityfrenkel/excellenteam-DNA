//
// Created by gity on 1/5/19.
//

#include "ShowCommand.h"
#include <string>


int ShowCommand::showRegister = Factory::Register("show", new ShowCommand);

std::string ShowCommand::run(std::vector<std::string> commandParams, DnaData* dnadata)
{
    size_t numChars;
    if(commandParams.size() > 1)
    {
        int _id = atoi(commandParams[1].substr(1, commandParams[1].length()).c_str());
        if(commandParams.size() > 2 )
        {
            numChars = atoi(commandParams[2].c_str());
        }
        else
        {
            numChars = 99;
        }

        return show(_id, numChars, dnadata);
    }

    return "You must provide a dna sequence!!";
}

std::string ShowCommand::show(int _id, size_t numChars, DnaData* dnadata)
{
    std::string show = dnadata->getDataStr(_id);

    std::string showAll = "[" + std::to_string(_id) + "] ";
    showAll += " " + dnadata->getNameById(_id);
    showAll += " " + dnadata->getMetadata(_id)->getStatus();
    showAll += "\n";

    size_t len = show.length();
    if(len < numChars)
        numChars = len;

    for(size_t i = 0; i < numChars; ++i)
    {
        showAll += show[i];
        if(i % 99 == 0 && i != 0)
            showAll += '\n';
    }

    return showAll;

}

