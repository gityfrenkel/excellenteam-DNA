//
// Created by gity on 12/25/18.
//

#ifndef DNAPROJECT_DNASEQUENCE_H
#define DNAPROJECT_DNASEQUENCE_H


#include "IDnaSequence.h"

class DnaSequence : public IDnaSequence
{
    explicit DnaSequence() {}
    explicit DnaSequence(char* dnaSequence);
    explicit DnaSequence(std::string& dnaSequence_s);
    DnaSequence(const DnaSequence& other);

    ~DnaSequence();

    SharePointer<IDnaSequence> operator=(const SharePointer<IDnaSequence> dnaSequence);
    SharePointer<IDnaSequence> operator=(const std::string& d);
    SharePointer<IDnaSequence> operator=(const char* d);

    bool operator==(const SharePointer<IDnaSequence> dnaSequence)const;
    bool operator!=(const SharePointer<IDnaSequence> dnaSequence)const;

    Nucleotid& operator [](size_t idx);
    const Nucleotid& operator [](size_t idx)const;
    friend ostream& operator<<(ostream& os, const SharePointer<IDnaSequence> dnaSequence);

    size_t get_Length()const;
    SharePointer<IDnaSequence> slicing(size_t from, size_t to);

private:
    Nucleotid* m_dnaSequence;
    size_t m_length;

    Nucleotid* getSequence();
    bool validDna(size_t length);
    void init_DnaSequence(const char* dnasequence);
    SharePointer<IDnaSequence> asigmentOp(const char*);

};

inline bool DnaSequence::validDna(size_t length)
{
    return (length % 3) == 0;
}

#endif //DNAPROJECT_DNASEQUENCE_H
