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



//    void* NewDnaFunc(char* dnaName, int dnaId, IDnaSequence* dnaSequence);
//    void* LoadDnaFunc(char* dnaName, int dnaId);
//    void* DnaShowFunc(char* dnaName, int dnaId);
//    void* DnaSaveFunc(char* dnaName, int dnaId);