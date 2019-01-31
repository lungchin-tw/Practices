

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Utilities/Public/TypeDefine.h"
#include "Utilities/Public/Environment.h"


class Container
{
public:
    static const Int32 MAX_LENGTH = 10;

    typedef std::vector<Int32> TIntArray;

    Container()
    {
        std::srand( std::time( nullptr ) );

        for( Int32 i = 0; i < MAX_LENGTH; i++ )
        {
            IntArray.push_back( std::rand() );
        }
    }

    const TIntArray& GetIntArray() const 
    {
        std::cout << "Container::GetIntArray" << std::endl;
        return IntArray; 
    }

    void Push( Int32 value )
    {
        IntArray.push_back( value );
        std::cout << "Container::Push, Value=" << value << ", Length=" << IntArray.size() << std::endl;
    }

    void Insert( Int32 pos, Int32 value )
    {
        IntArray.insert( IntArray.begin() + pos, value );
        std::cout << "Container::Insert, Pos=" << pos << ", Value=" << value << ", Length=" << IntArray.size() << std::endl;
    }

private:
    TIntArray IntArray;
};


int main()
{
    Environment::Get().Print();

    std::cout << "========== List Container: Original ===============" << std::endl;

    Container container;
    Int32 index = 0;
    for( Int32 elem : container.GetIntArray() )
    {   
        std::cout << "Elem(" << index++ << ") in Container: " << elem << std::endl;
    }

    std::cout << "====================================================" << std::endl;

    std::cout << "========== List Container: Push in the process ===============" << std::endl;

    index = 0;
    const Container::TIntArray& ref = container.GetIntArray();
    for( Int32 elem : ref )
    {   
        std::cout << "Elem(" << index++ << ") in Container: " << elem << std::endl;

        if( index == 5 )
        {
            container.Push( std::rand() );
            container.Insert( 0, std::rand() );
        }
    }

    index = 0;
    for( Int32 elem : ref )
    {   
        std::cout << "Elem(" << index++ << ") in Container: " << elem << std::endl;
    }

    std::cout << "===============================================================" << std::endl;
    
    return 0;
}