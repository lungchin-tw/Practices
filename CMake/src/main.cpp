
#include <iostream>
#include "TestLib/TestLib.h"
#include "../external/TestDll/inc/TestDll.h"

int main(int, char**)
{
   std::cout << "Hello, CMakePractice!\n";

   CMakePracticeTestLib test_lib;
   std::cout << test_lib.Hello().c_str() << std::endl;

   CMakePracticeTestDll test_dll;
   std::cout << test_dll.Hello().c_str() << std::endl;
}
