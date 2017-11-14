/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/


#include <iostream>
#include <typeinfo>
#include <string>

#include "CodeBoilerplate.h"


struct Data
{
    double DX;
    int    IY;
};


template<typename T, typename U>
auto Max( T t, U u ) -> decltype( t + u )
{
    std::cout << "===========" << FUNCTION_NAME << "===========" << std::endl;
    std::cout << "T : " << typeid( T ).name() << ", HashCode :" << typeid( T ).hash_code() << std::endl;
    std::cout << "U : " << typeid( U ).name() << ", HashCode :" << typeid( U ).hash_code() << std::endl;
    std::cout << "==========================================" << std::endl;
    return ( t > u ) ? t : u;
}

int main()
{
    const Data data = {1.0, 2};

    decltype( data.DX ) x;
    x = data.DX;
    
    std::cout << "TypeName : " << typeid( decltype( data ) ).name() << ", HashCode :" << typeid( decltype( data ) ).hash_code() << std::endl;
    std::cout << "TypeName : " << typeid( decltype( data.DX ) ).name() << ", HashCode :" << typeid( decltype( data.DX ) ).hash_code() << std::endl;
    std::cout << "TypeName : " << typeid( decltype( Data::IY ) ).name() << ", HashCode :" << typeid( decltype( Data::IY ) ).hash_code() << std::endl;

    std::cout << std::endl;
    decltype( Max( data.DX, data.IY ) ) result = Max( data.DX, data.IY );
    std::cout << "Result TypeName : " << typeid( result ).name() << ", Result :" << result << std::endl;
    std::cout << std::endl;

    std::cout << "Max : " << typeid( Max( data.DX, data.IY ) ).name() << ", HashCode :" << typeid( Max( data.DX, data.IY ) ).hash_code() << std::endl;

    return 0;
}