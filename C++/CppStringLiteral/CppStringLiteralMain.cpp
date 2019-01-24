/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/

#include <string>
#include <iostream>


std::string operator ""_abc( const char* value, std::size_t len )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl << value << std::endl << len << std::endl;
    return __PRETTY_FUNCTION__;
}


int main()
{
    std::cout << "123"_abc << std::endl;
    return 0;
}