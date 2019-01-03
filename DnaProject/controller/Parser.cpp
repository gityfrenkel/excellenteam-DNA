//
// Created by gity on 12/29/18.
//

#include <cstring>
#include "Parser.h"

std::vector<std::string> Parser::parse(std::string command)
{
    std::vector<std::string> parsedPrompt;

    char *commandStr = strdup(command.c_str());

    char *token = std::strtok(commandStr, " ");
    while (token != NULL)
    {
        parsedPrompt.push_back(token);
        token = std::strtok(NULL, " ");
    }

    return parsedPrompt;
}
