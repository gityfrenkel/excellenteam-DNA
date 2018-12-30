//
// Created by gity on 12/29/18.
//
#include "WriteFile.h"
#include <fstream>
using std::ofstream;

WriteFile::WriteFile(const char * path) :m_fileName(path)
{}

WriteFile::WriteFile(WriteFile const & other) : m_fileName(other.m_fileName)
{}

WriteFile::~WriteFile()
{}

void WriteFile::write(const DnaSequence dna)
{
    ofstream myfile;
    myfile.open(m_fileName.c_str());

    if (!myfile.is_open())
        throw std::logic_error("unable to open file");

    myfile << dna;
    myfile.close();
}