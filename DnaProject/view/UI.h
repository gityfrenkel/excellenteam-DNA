//
// Created by gity on 12/29/18.
//

#ifndef DNAPROJECT_I_UI_H
#define DNAPROJECT_I_UI_H

#include <iostream>

class UI
{
public:
    virtual std::string getPrompt() = 0;
    virtual void printToScreen(std::string toPrint) = 0;
};
#endif //DNAPROJECT_I_UI_H
