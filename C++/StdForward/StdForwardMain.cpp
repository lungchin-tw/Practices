/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/


#include <iostream>
#include <utility>
#include <memory>

#include "CodeBoilerplate.h"


struct A 
{
    explicit A( const int&& n ) 
    { 
        std::cout << FUNCTION_NAME << ", rvalue overload, n=" << n << "\n"; 
    }

    explicit A( const int& n )
    {
        std::cout << FUNCTION_NAME << ", lvalue overload, n=" << n << "\n"; 
    }
};

template<class T1, class T2, class T3>
void WithoutForward( T1&& t1, T2&& t2, T3&& t3 )
{
    std::cout << FUNCTION_NAME << "\n"; 
    A a1( t1 );
    A a2( t2 );
    A a3( t3 );
}

template<class T1, class T2, class T3>
void WithForward( T1&& t1, T2&& t2, T3&& t3 )
{
    std::cout << FUNCTION_NAME << "\n"; 
    A a1( std::forward<T1>(t1) );
    A a2( std::forward<T2>(t2) );
    A a3( std::forward<T3>(t3) );
}


int main()
{
    std::cout << "A :\n";
    A a1( 1 );

    int i = 2;
    A a2( i );

    std::cout << "\n";
    WithoutForward( 1, i, 3 );

    std::cout << "\n";
    WithForward( 1, i, 3 );

    return 0;
}