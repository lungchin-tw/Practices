

#include <iostream>
#include "DeclareStatic.h"
#include "Utilities/Public/Type2String.h"
#include "Utilities/Public/Environment.h"


int main()
{
    Environment::Get().Print();

    GlobalIntPtr = new int[10];

    std::cout << "main::GlobalIntPtr(" << Address2String( &GlobalIntPtr ) << ") Is Valid ? " << Bool2String( (GlobalIntPtr != nullptr ) ) << std::endl;

    IntPtrPtr another_addr = GetAnotherGlobalIntPtrPtr();
    std::cout << "GetAnotherGlobalIntPtr(" << Address2String( &another_addr ) << ") Is Valid ? " << Bool2String( (GetAnotherGlobalIntPtr() != nullptr ) ) << std::endl;
    
    return 0;
}