/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/

#include <iostream>

#include "Include/Utility.h"
#include "Include/IsPointerType.h"


int main()
{
    std::cout << "is int a pointer type ? " << Bool2String< IsPointerType<int>::Value >()<< std::endl;
    std::cout << "is int* a pointer type ? " << Bool2String< IsPointerType<int*>::Value >()<< std::endl;
    return 0;
}