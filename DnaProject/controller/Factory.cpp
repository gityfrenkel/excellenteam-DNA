//
// Created by gity on 12/30/18.
//

#include "Factory.h"
#include <string>

//std::map<std::string, Icommand*> Factory::m_commandMap;

//Icommand* Factory::getCommand(std::string commadName)
//{
//    Icommand* icommand = NULL;
//    std::map<std::string, Icommand*>::iterator it;
//    std::pair<std::map<std::string, Icommand*>::iterator, bool> result;
//
//    if(commadName == "new")
//    {
//        icommand = new NewCommand;
//    }
//
//    if(commadName == "load")
//    {
//        icommand = new LoadCommand;
//    }
//    if(commadName == "save")
//    {
//        icommand = new SaveCommand;
//    }
//
//    result = m_commandMap.insert(std::pair<std::string, Icommand *>(commadName, icommand));
//    if(result.second == false)
//    {
//        it = m_commandMap.find(commadName);
//        icommand = it->second;
//    }
//
//    return icommand;
//}


int Factory::Register(std::string commandName, Icommand* icommand)
{
    Factory::getMap().insert(std::pair<std::string, Icommand*>(commandName, icommand));

    return 1;
}

std::map<std::string, Icommand*>& Factory::getMap()
{
    static std::map<std::string, Icommand*> m_commandMap;

    return m_commandMap;
}

Icommand* Factory::getCommand(std::string commadName)
{
    std::map<std::string, Icommand*>::iterator it;

    it = Factory::getMap().find(commadName);
    if(it != Factory::getMap().end())
    {
        return it->second;
    }

    return NULL;
}


