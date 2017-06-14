/*
** (c) Copyright SOFTSTAR ENTERTAINMENT INC. All Rights Reserved.
*/

#include <iostream>
#include "Poco/SharedLibrary.h"
#include "PocoSharedLibrary.h"

void pocoSharedLibraryPractice()
{
    std::cout << std::endl << "============== " << __PRETTY_FUNCTION__ << " ==============" << std::endl;

    std::cout << "Library Suffix : " << Poco::SharedLibrary::suffix() << std::endl;

    std::cout << "===========================================================" << std::endl;
}