
/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/


#include "Type2String.h"
#include <sstream>


std::string Bool2String( bool value )
{
    return value ? "True" : "False";
};

std::string Address2String( const void* value )
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}