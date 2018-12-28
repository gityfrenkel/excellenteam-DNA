#include <iostream>
#include "../model/Nucleotid.h"

void testNucleotid()
{
    std::cout << "= = = = start test nucleotid = = = =" << std::endl << std::endl;

    try
    {
        Nucleotid nucleotidNotValid('r');
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "ctor with invalid argiment success " << std::endl << std::endl;
    }

    Nucleotid nucleotid('t');
    std::cout << "ctor with char:\n my nucleotid = : " << nucleotid << std::endl << std::endl;

    Nucleotid nucleotid1;
    std::cout << "default ctor:\n my nucleotid = : " << nucleotid1 << std::endl << std::endl;

    nucleotid = nucleotid1;
    std::cout << "asigment operator with Nucleotid:\n my nucleotid = : " << nucleotid << std::endl << std::endl;

    nucleotid = 't';
    std::cout << "asigment operator with char:\n my nucleotid = : " << nucleotid << std::endl << std::endl;

    nucleotid = nucleotid1.getNucleotid();
    std::cout << "asigment operator with getNucleotid:\n my nucleotid = : " << nucleotid << std::endl << std::endl;

    nucleotid = nucleotid.getPairNucleotid();
    std::cout << "asigment operator with getPairNucleotid:\n my pair nucleotid = : " << nucleotid << std::endl << std::endl;

    std::cout << "= = = = end test nucleotid = = = =" << std::endl;
}

int main()
{
    testNucleotid();
    return 0;
}
