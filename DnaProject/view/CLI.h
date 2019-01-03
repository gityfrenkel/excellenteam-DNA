//
// Created by gity on 12/29/18.
//

#ifndef DNAPROJECT_UI_H
#define DNAPROJECT_UI_H


#include "UI.h"


class CLI : public UI
{
public:
    CLI(std::string prompt = "> cmd >>> ");
    std::string getPrompt();

private:
    std::string m_prompt;
};


#endif //DNAPROJECT_UI_H
