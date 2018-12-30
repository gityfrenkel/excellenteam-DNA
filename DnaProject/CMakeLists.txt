cmake_minimum_required(VERSION 3.12)
project(DnaProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(DnaProject Tests/main.cpp model/Nucleotid.h model/Nucleotid.cpp model/dnaSequence.cpp model/dnaSequence.h model/IDnaSequence.h model/Shared_pointer.h Tests/Tests.cpp Tests/Tests.h model/DnaData.h model/ReadFile.cpp model/ReadFile.h model/WriteFile.cpp model/WriteFile.h view/CLI.cpp view/CLI.h view/UI.h model/DnaData.cpp)