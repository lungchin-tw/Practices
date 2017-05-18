
#include <stdio.h>

template<int n> struct accumulate { enum{ value = n + accumulate<n-1>::value }; };
template<> struct accumulate<1> { enum{ value=1 }; };

int main()
{
    printf( "Hello, meta programming, Result=%d.\n", accumulate<3>::value );
    return 0;
}