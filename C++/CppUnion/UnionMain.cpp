/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/


#include <iostream>


union UA
{
    UA( short l, short h ) : Split( l, h ) {}
    UA() : Value ( 0 ) {}


    int Value;

    struct TSplit
    {
        TSplit( short l, short h ) : Low( l ), High( h ) {}

        short Low;
        short High; 
    } Split;
    
};


int main()
{
    std::cout << __FUNCTION__ << std::endl;

    UA( 1, 2 );
    UA();
 
    return 0;
}