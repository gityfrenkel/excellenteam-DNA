//
// Created by gity on 12/30/18.
//

#include "NewCommand.h"
#include "../model/dnaSequence.h"
#include "../model/Shared_pointer.h"

int NewCommand::SerialNameNumber = 0;

void NewCommand::run(std::vector<std::string> commandParams, DnaData* dnadata)
{
    std::string  name;
    try
    {

        if(commandParams.size() > 1)
        {
            IDnaSequence* dnaSequence = new DnaSequence(commandParams[1]);
            SharePointer<IDnaSequence> idnaSequence(dnaSequence);

            if(commandParams.size() > 2 )
            {
                name = commandParams[2];
                if(dnadata->exist(name))
                {
                    name = nextSerialName(dnadata);
                }
            }
            else
            {
                name = nextSerialName(dnadata);
            }

            dnadata->add(++SerialNumber, name, idnaSequence);


            std::cout << dnadata->StrToPrint(name) << std::endl;
        }
        else
        {
            std::cout << "You must provide a dna sequence!!" << std::endl;
        }

    }
    catch (const std::bad_alloc)
    {
        throw std::bad_alloc();
    }
    catch (const std::invalid_argument& e)
    {
        throw std::invalid_argument(e.what());
    }

}

std::string NewCommand::nextSerialName(DnaData* dnaData)
{
    std::ostringstream oss;
    oss << ++SerialNameNumber;

    std::string nextName = "seq_" + oss.str();
    while(dnaData->exist(nextName))
    {
        std::ostringstream oss;
        oss << ++SerialNameNumber;
        nextName = "seq_" + oss.str();
    }

    return nextName;
}