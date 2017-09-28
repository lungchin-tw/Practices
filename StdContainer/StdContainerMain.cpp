/*
** Copyright CHEN, LUNG-CHIN. All Rights Reserved.
*/

#include <iostream>
#include <queue>
#include <set>


void PracticeQueue();
void PracticeSet();

int main()
{
    PracticeQueue();
    PracticeSet();
    return 0;
}

void PracticeQueue()
{
    std::cout << __FUNCTION__ << std::endl;

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

    std::cout << std::endl << std::endl;
}

void PracticeSet()
{
    std::cout << __FUNCTION__ << std::endl;

    std::set<int> int_set;
    int_set.insert( 1 );
    int_set.insert( 3 );
    int_set.insert( 5 );
    int_set.insert( 1 );

    std::cout << int_set.size() << std::endl;;
    std::cout << *int_set.begin() << std::endl;;
    std::cout << int_set.count( 1 ) << std::endl;;
    std::cout << int_set.count( 7 ) << std::endl;;
    

    int_set.erase( 1 );
    std::cout << int_set.count( 1 ) << std::endl;;
    std::cout << int_set.size() << std::endl;;

    std::cout << std::endl << std::endl;
}