

#include <iostream>
// #include "ExternDeclaration.h" I don't need to include the header. Because I use extern instead


extern int NotDefinedInteger;
extern int DefinedInteger = 0; // Defined!!! but it will throw a warning in compilation.


/*
** Multi Declaration via keyword "extern"
*/
extern float CrossFileFloat;
extern float CrossFileFunction();


int main( void )
{
    //NotDefinedInteger = 10; // Comment this line, or it will throw an error in compilation.

    DefinedInteger = 20;
    std::cout << "main::DefinedInteger = " << DefinedInteger << std::endl;
    std::cout << "main::Before CrossFileFloat = " << CrossFileFloat << std::endl;
    std::cout << "main::CrossFileFunction = " << CrossFileFunction() << std::endl;
    std::cout << "main::After CrossFileFloat = " << CrossFileFloat << std::endl;
    
    return 0;
}