//
// Created by gity on 1/6/19.
//

#include "ListCommand.h"

int ListCommand::listRegister = Factory::Register("list", new ListCommand);

std::string ListCommand::run(std::vector<std::string> commandParams, DnaData* dnadata)
{
    std::map<int, MetaData*>::iterator it;
    std::string list = "";
    for(it = dnadata->getMap()->begin(); it != dnadata->getMap()->end(); ++it)
    {
        if(it->second->getStatus() == "new")
            list += "o ";
        else
        {
            if(it->second->getStatus() == "saved")
                list += "- ";
            else
                list += "* ";
        }

        list += "[" + std::to_string(it->second->getId()) + "] ";
        list += it->second->getName() + ": ";

        std::string dnaByStr = "";
        size_t len = it->second->getDna()->get_Length();
        for(size_t i = 0; i < len; ++i)
            dnaByStr += it->second->getDna()->getSequence()[i].getNucleotid();

        if(dnaByStr.length() > 40)
        {
            list += dnaByStr.substr(0, 32);
            list += "...";
            list += dnaByStr.substr(dnaByStr.length()-3, dnaByStr.length()) + '\n';
        }
        else
        {
            list += dnaByStr + '\n';
        }

    }

    return list.substr(0, list.length() - 1);

}
