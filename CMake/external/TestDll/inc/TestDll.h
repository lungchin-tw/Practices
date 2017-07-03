
#ifndef _TESTDLL_H_
#define _TESTDLL_H_

#include <string>

class CMakePracticeTestDll
{
public:
    CMakePracticeTestDll();
    ~CMakePracticeTestDll();

    std::string Hello() const;
};


#endif