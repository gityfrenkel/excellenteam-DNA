//
// Created by gity on 12/25/18.
//

#ifndef DNAPROJECT_DNASEQUENCE_H
#define DNAPROJECT_DNASEQUENCE_H
#include "IDnaSequence.h"

class DnaSequence : public IDnaSequence
{
public:
    explicit DnaSequence(const char* dnaSequence);
    explicit DnaSequence(std::string& dnaSequence_s);

    ~DnaSequence();

    IDnaSequence* operator=(const std::string& d);
    IDnaSequence* operator=(const char* d);

    bool operator==(const IDnaSequence* dnaSequence) const;
    bool operator!=(const IDnaSequence* dnaSequence) const;

    Nucleotid& operator [](size_t idx);
    const Nucleotid operator [](size_t idx)const;
    friend ostream& operator<<(ostream& os, const DnaSequence dnaSequence);

    size_t get_Length() const;
    Nucleotid* getSequence() const;
    std::string getSeqStr();

private:
    Nucleotid* m_dnaSequence;
    size_t m_length;

    void init_DnaSequence(const char* dnasequence);
    bool validDna(size_t length);
    IDnaSequence* asigmentOp(const char*);
};

inline bool DnaSequence::validDna(size_t length)
{
    return (length % 3) == 0;
}

#endif //DNAPROJECT_DNASEQUENCE_H
