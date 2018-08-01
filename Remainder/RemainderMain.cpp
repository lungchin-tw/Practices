

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>


typedef int Int32;
typedef unsigned int UInt32;
typedef unsigned char Byte;


template< typename T >
T Remainder_RhindPapyrus( T a, T b )
{
    if( a <= 0 )
    {
        throw std::runtime_error( "Critical Error : a should > 0" );
    } 
    
    if( b <= 0 )
    {
        throw std::runtime_error( "Critical Error : b should > 0" );
    }
        
    if( a < b )
    {
         return a;
    }

    if( ( a - b ) >= b )
    {
        a = Remainder_RhindPapyrus( a, ( b + b ) );
        if( a < b )
        {
            return a;
        }
    }

    return ( a - b );
}

int main()
{
    std::srand( std::time( nullptr ) );

    const Int32 divisor = 7;
    const Int32 numbers_len = 10;

    for( Int32 i = 0; i < numbers_len; i++ )
    {
        try
        {
            printf( "divide %d by %d, remainder = %d\n", i, divisor, Remainder_RhindPapyrus( i, divisor ) );

            Int32 number = std::rand();
            printf( "divide %d by %d, remainder = %d\n", number, divisor, Remainder_RhindPapyrus( number, divisor ) );
        }
        catch( const std::exception& e )
        {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}