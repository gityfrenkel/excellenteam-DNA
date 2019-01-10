//
// Created by gity on 12/30/18.
//

//#include "RunCommands.h"
#include "Factory.cpp"
#include "Icommand.cpp"
#include "LoadCommand.cpp"
#include "NewCommand.cpp"
#include "Parser.cpp"
#include "RunCommands.cpp"
#include "SaveCommand.cpp"
#include "ShowCommand.cpp"
#include "ListCommand.cpp"

#include "../model/DnaData.cpp"
#include "../model/dnaSequence.cpp"
#include "../model/MetaData.cpp"
#include "../model/Nucleotid.cpp"
#include "../model/ReadFile.cpp"
#include "../model/WriteFile.cpp"
#include "../model/DnaSeqPair.cpp"

#include "../view/CLI.cpp"

int main()
{
    UI* m_ui = new CLI;
    DnaData data;

    RunCommands mainLoop(data, m_ui);
    mainLoop.Run();
}
