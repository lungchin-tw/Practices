

#include <iostream>
#include "Utilities/Public/Environment.h"


int main()
{
    Environment::Get().Print();

    std::cout << "~2: " << ~2 << std::endl;
    std::cout << "~1: " << ~1 << std::endl;
    std::cout << "~0: " << ~0 << std::endl;
    std::cout << "~(-1): " << ~(-1) << std::endl;
    
    return 0;
}