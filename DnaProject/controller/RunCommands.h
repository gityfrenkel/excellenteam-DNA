//
// Created by gity on 12/30/18.
//

#ifndef DNAPROJECT_RUNCOMMANDS_H
#define DNAPROJECT_RUNCOMMANDS_H

#include "Factory.h"
#include "../view/CLI.h"
#include "../controller/Parser.h"

class RunCommands
{
public:
    RunCommands(DnaData dnadata, UI* ui);
    void Run();

private:
    DnaData m_dnaData;
    UI* m_ui;

};

#endif //DNAPROJECT_RUNCOMMANDS_H
