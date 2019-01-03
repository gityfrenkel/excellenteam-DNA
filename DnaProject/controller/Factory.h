//
// Created by gity on 12/30/18.
//

#ifndef DNAPROJECT_FACTORY_H
#define DNAPROJECT_FACTORY_H

#include "NewCommand.h"
#include "LoadCommand.h"

class Factory
{
public:

    static Icommand* getCommand(std::string commadName);
    //static Factory* Register();

private:

    static std::map<std::string, Icommand*> m_commandMap;
    //static  Factory m_initializ;
};



#endif //DNAPROJECT_FACTORY_H

