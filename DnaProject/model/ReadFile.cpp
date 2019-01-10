//
// Created by gity on 12/29/18.
//

#include "ReadFile.h"
#include <fstream>
using std::ifstream;

ReadFile::ReadFile(const char * path)
{
    std::ifstream myfile(path);
    if (!myfile.is_open())
        throw std::logic_error("unable to open file");
    while (!myfile.eof())
    {
        myfile >> m_fileData;
    }
    myfile.close();
}

ReadFile::ReadFile(ReadFile const & other) :m_fileData(other.m_fileData)
{}

ReadFile::~ReadFile()
{}

DnaSequence ReadFile::read()
{
    std::string d = m_fileData;
    DnaSequence DNA(d);
    return DNA;
}
