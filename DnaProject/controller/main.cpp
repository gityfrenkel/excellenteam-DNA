//
// Created by gity on 12/30/18.
//

#include "RunCommands.h"


int main()
{
    UI* m_ui = new CLI;
    DnaData data;

    RunCommands mainLoop(data, m_ui);
    mainLoop.Run();
}
