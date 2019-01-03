//
// Created by gity on 12/25/18.
//

#ifndef DNAPROJECT_IDNASEQUENCE_H
#define DNAPROJECT_IDNASEQUENCE_H

#include "Nucleotid.h"

class IDnaSequence
{
public:

    virtual ~IDnaSequence(){}

    virtual IDnaSequence* operator=(const std::string& idnaStr) = 0;
    virtual IDnaSequence* operator=(const char* idnaChar) = 0;

    virtual bool operator==(const IDnaSequence* idnaSequence) const = 0;
    virtual bool operator!=(const IDnaSequence* idnaSequence) const = 0;

    virtual Nucleotid& operator [](size_t idx) = 0;
    virtual const Nucleotid operator [](size_t idx) const = 0;

    friend ostream& operator<<(ostream& os, const IDnaSequence* idnaSequence);

    virtual size_t get_Length() const = 0;
    virtual Nucleotid* getSequence() const = 0;

    virtual std::string getSeqStr() = 0;

};

#endif //DNAPROJECT_IDNASEQUENCE_H
