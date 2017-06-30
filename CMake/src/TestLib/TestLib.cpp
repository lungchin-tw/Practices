
#include <string>
#include <sstream>
#include "TestLib.h"

CMakePracticeTestLib::CMakePracticeTestLib(){}
CMakePracticeTestLib::~CMakePracticeTestLib(){}

std::string CMakePracticeTestLib::Hello() const
{
    std::ostringstream string_stream;
    string_stream << __PRETTY_FUNCTION__;
    std::string result = string_stream.str();
    return result;
}
