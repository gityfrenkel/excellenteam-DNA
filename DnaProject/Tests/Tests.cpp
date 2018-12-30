//
// Created by gity on 12/28/18.
//
#include "Tests.h"

void Tests::testNucleotid()
{
    std::cout << "= = = = start test nucleotid = = = =" << std::endl << std::endl;

    try
    {
        Nucleotid nucleotidNotValid('r');
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "ctor with invalid argument success " << std::endl << std::endl;
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

void Tests::testDnaSequence()
{
    std::cout << "= = = = start test dnaSequence = = = =" << std::endl << std::endl;

    try
    {
        DnaSequence dnaSequence("ATCGfGCAAAAAA");
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "ctor with invalid nucleotid argument successed " << std::endl << std::endl;
    }

    try
    {
        DnaSequence dnaSequence("ATCGGCAAAAAATT");
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "ctor with invalid length successed " << std::endl << std::endl;
    }

    char dna[6] = {'A', 'C', 'G', 'T','T', 'G'};
    char newDna[9] = {'A', 'T', 'G', 'A', 'T', 'G', 'A', 'T', 'G'};
    std::string dnas = "AAA";

    DnaSequence dnaSequence(dna);
    std::cout << "ctor with char*:\nmy dna = : " << dnaSequence << std::endl;
    std::cout << "dna's length =: " << dnaSequence.get_Length() << std::endl << std::endl;

    DnaSequence dnaSequence1(dnas);
    std::cout << "ctor with string:\nmy dna = : " << dnaSequence1 << std::endl;
    std::cout << "dna's length =: " << dnaSequence1.get_Length() << std::endl << std::endl;

    dnaSequence1 = "TTT";
    std::cout << "asigment operator with string:\nmy new dna = : " << dnaSequence1 << std::endl;
    std::cout << "dna's new length =: " << dnaSequence1.get_Length() << std::endl << std::endl;

    dnaSequence = newDna;
    std::cout << "asigment operator with char*:\nmy new dna = : " << dnaSequence << std::endl;
    std::cout << "dna's new length =: " << dnaSequence.get_Length() << std::endl << std::endl;

    IDnaSequence* iDnaSequence = new DnaSequence(newDna);

    if(iDnaSequence == &dnaSequence)
    {
        std::cout << dnaSequence << "==" << dnaSequence1 << std::endl;
    }

    if(iDnaSequence != &dnaSequence)
    {
        std::cout << dnaSequence << " != " << dnaSequence1 << std::endl;
    }

}