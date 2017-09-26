/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/

#include <iostream>
#include <vector>
#include <queue>


int main()
{
    std::queue<char> char_queue;

    char_queue.push( 'a' );
    char_queue.push( 'b' );
    char_queue.push( 'c' );

    while( char_queue.size() > 0 )
    {
        std::cout << char_queue.size();
        std::cout << char_queue.front();
        char_queue.pop();

    }
    return 0;
}