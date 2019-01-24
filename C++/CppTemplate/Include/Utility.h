
/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/


#include <string>


template<bool value>
const std::string& Bool2String()
{
    static const std::string Value = "False";
    return Value;
};

template<>
const std::string& Bool2String<true>()
{
    static const std::string Value = "True";
    return Value;
}