
#include <iostream>
#include "TestLib/TestLib.h"

int main(int, char**)
{
   std::cout << "Hello, CMakePractice!\n";

   CMakePracticeTestLib test_lib;
   std::cout << test_lib.Hello().c_str() << std::endl;
}
