#include <string>
#include <sstream>
#include "TestDll.h"

CMakePracticeTestDll::CMakePracticeTestDll(){}
CMakePracticeTestDll::~CMakePracticeTestDll(){}

std::string CMakePracticeTestDll::Hello() const
{
    std::ostringstream string_stream;
    string_stream << __PRETTY_FUNCTION__;
    std::string result = string_stream.str();
    return result;
}
