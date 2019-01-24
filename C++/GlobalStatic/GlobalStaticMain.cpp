

#include <iostream>
#include "DeclareStatic.h"
#include "Utilities/Public/Type2String.h"


int main()
{
    GlobalIntPtr = new int[10];

    std::cout << "main::GlobalIntPtr Is Valid ? " << Bool2String( (GlobalIntPtr != nullptr ) )<< std::endl;
    std::cout << "GetAnotherGlobalIntPtr Is Valid ? " << Bool2String( (GetAnotherGlobalIntPtr() != nullptr ) )<< std::endl;
    
    return 0;
}