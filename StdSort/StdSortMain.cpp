

#include <vector>
#include <iostream>
#include <algorithm>


std::vector<int> IntList;


template<class TYPE>
bool Greater( const TYPE& a, const TYPE& b )
{
    return ( a > b );
}

template<class TYPE>
bool Less( const TYPE& a, const TYPE& b )
{
    return ( a < b );
}

int main()
{
    IntList.push_back( 10 );
    IntList.push_back( 1 );
    IntList.push_back( 9 );
    IntList.push_back( 3 );

    std::cout << "Before : ";
    for( auto elem : IntList ) std::cout << elem << " ";
    std::cout << std::endl;

    std::sort( IntList.begin(), IntList.end(), Greater<int> );

    std::cout << "After : ";
    for( auto elem : IntList ) std::cout << elem << " ";
    std::cout << std::endl;

    IntList.push_back( 100 );
    std::sort( IntList.begin(), IntList.end(), Greater<int> );
    std::cout << "After : ";
    for( auto elem : IntList ) std::cout << elem << " ";
    std::cout << std::endl;

    std::sort( IntList.begin(), IntList.end(), Less<int> );
    std::cout << "After : ";
    for( auto elem : IntList ) std::cout << elem << " ";
    std::cout << std::endl;
    
    return 0;
}