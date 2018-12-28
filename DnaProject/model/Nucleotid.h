//
// Created by gity on 12/25/18.
//
#ifndef DNAPROJECT_NUCLEOTID_H
#define DNAPROJECT_NUCLEOTID_H
#include <iostream>
using std::ostream;
using std::string;

class Nucleotid
{
public:
    Nucleotid();
    Nucleotid(char nucleotid);

    Nucleotid& operator=(const char nucleotid);
    Nucleotid& operator=(const Nucleotid& nucleotid);
    bool operator==(const Nucleotid& nucleotid)const;
    bool operator!=(const Nucleotid& nucleotid)const;
    friend ostream& operator<<(ostream& os, const Nucleotid& nucleotid);

    Nucleotid getPairNucleotid() const;
    char getNucleotid() const;
    char validNucleotid(const char nucleotid);


private:
    char m_nucleotid;
};


inline char Nucleotid::validNucleotid(char nucleotid)
{
    nucleotid = (char)toupper((int)nucleotid);
    if (nucleotid != 'T' && nucleotid != 'C' && nucleotid != 'G' && nucleotid != 'A')
        throw std::invalid_argument("the nucleotid is not valide");
    return nucleotid;
}

inline Nucleotid::Nucleotid():m_nucleotid('A')
{}

inline Nucleotid::Nucleotid(char nucleotid)
{
    try
    {
        m_nucleotid = validNucleotid(nucleotid);
    }
    catch(std::invalid_argument& e)
    {
        throw std::invalid_argument(e.what());
    }

}

#endif //DNAPROJECT_NUCLEOTID_H
