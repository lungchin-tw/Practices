
#include <iostream>

#include "TestClass.cpp"


int main()
{
    TestClass tca(1), tcb(2), tcc(3), tcd(4);

    std::cout << std::endl << "Pre TransferObjectByValue" << std::endl;
    TransferObjectByValue( tca, tcb );
    
    std::cout << std::endl << "Pre TransferObjectByRef" << std::endl;
    TransferObjectByRef( tca, tcb );

    std::cout << std::endl << "Pre SwapTestClassByRef" << std::endl;
    SwapTestClassByRef( tca, tcb );

    std::cout << std::endl << tca.X.size() << std::endl;
    std::cout << tcb.X.size() << std::endl;

    TestClass result = tca + tcb + tcc + tcd;
    
    return 0;
}