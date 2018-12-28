//
// Created by gity on 12/25/18.
//

#ifndef DNAPROJECT_IDNASEQUENCE_H
#define DNAPROJECT_IDNASEQUENCE_H

#include <iostream>
#include "Nucleotid.h"
#include "Shared_pointer.h"
using std::ostream;

class IDnaSequence
{
public:

    virtual SharePointer<IDnaSequence> operator=(const SharePointer<IDnaSequence> idnaSequence) = 0;
    virtual SharePointer<IDnaSequence> operator=(const std::string& idnaStr) = 0;
    virtual SharePointer<IDnaSequence> operator=(const char* idnaChar) = 0;

    virtual bool operator==(const SharePointer<IDnaSequence> idnaSequence)const = 0;
    virtual bool operator!=(const SharePointer<IDnaSequence> idnaSequence)const = 0;

    virtual Nucleotid& operator [](size_t idx) = 0;
    virtual const Nucleotid& operator [](size_t idx)const = 0;
    friend ostream& operator<<(ostream& os, const SharePointer<IDnaSequence> idnaSequence);

    virtual size_t get_Length()const = 0;
    virtual Nucleotid* getSequence();
    virtual SharePointer<IDnaSequence> slicing(size_t from, size_t to) = 0;

};

#endif //DNAPROJECT_IDNASEQUENCE_H
