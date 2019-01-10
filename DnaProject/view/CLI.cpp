//
// Created by gity on 12/29/18.
//


#include "CLI.h"

CLI::CLI(std::string prompt):m_prompt(prompt)
{}

std::string CLI::getPrompt()
{
    std::cout << m_prompt;
    std::string command;
    std::getline(std::cin, command);

    return command;
}

void CLI::printToScreen(std::string toPrint)
{
    std::cout << toPrint << std::endl;
}
