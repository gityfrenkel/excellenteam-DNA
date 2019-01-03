//
// Created by gity on 12/30/18.
//

#include "RunCommands.h"


RunCommands::RunCommands(DnaData dnadata, UI* ui)
{
    m_ui = new CLI;
    m_dnaData = dnadata;
}

void RunCommands::Run()
{
    while (true)
    {
        std::string command = m_ui->getPrompt();
        std::vector<string> parsedCommand = Parser::parse(command);

        if(parsedCommand.size() == 0)
        {
            continue;
        }
        if(parsedCommand[0] == "exit")
        {
            return;
        }

        Factory::getCommand(parsedCommand[0])->run(parsedCommand, &m_dnaData);
    }
}
