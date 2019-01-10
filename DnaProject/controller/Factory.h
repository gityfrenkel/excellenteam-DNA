//
// Created by gity on 12/30/18.
//

#ifndef DNAPROJECT_FACTORY_H
#define DNAPROJECT_FACTORY_H

//#include "NewCommand.h"
//#include "LoadCommand.h"
//#include "SaveCommand.h"
#include "Icommand.h"

class Factory
{
public:

    static Icommand* getCommand(std::string commadName);
    static std::map<std::string, Icommand*>& getMap();
    static int Register(std::string commandName, Icommand* command);

//private:

    //static std::map<std::string, Icommand*> m_commandMap;
};



#endif //DNAPROJECT_FACTORY_H

