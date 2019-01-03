//
// Created by gity on 12/30/18.
//

#include "Factory.h"
#include <string>

std::map<std::string, Icommand*> Factory::m_commandMap;

//Factory* Factory::m_initializ = Register();

Icommand* Factory::getCommand(std::string commadName)
{
    Icommand* icommand = NULL;
    std::map<std::string, Icommand*>::iterator it;
    std::pair<std::map<std::string, Icommand*>::iterator, bool> result;

    if(commadName == "new")
    {
        icommand = new NewCommand;
    }

    if(commadName == "load")
    {
        icommand = new LoadCommand;
    }

    result = m_commandMap.insert(std::pair<std::string, Icommand *>(commadName, icommand));
    if(result.second == false)
    {
        it = m_commandMap.find(commadName);
        icommand = it->second;
    }

    return icommand;
}

//Factory* Factory::Register()
//{
//    return NULL;
//}
