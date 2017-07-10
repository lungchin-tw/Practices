
#include <iostream>

class TestClass
{
public:
    TestClass()
        : X( 0 )
        , Y( 1 )
        , Z( 2 )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    TestClass( const TestClass& other )
        : X( other.X )
        , Y( other.Y )
        , Z( other.Z )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        *this = other;
    }

    TestClass( const TestClass&& other )
        : X( other.X )
        , Y( other.Y )
        , Z( other.Z )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    TestClass& operator =( const TestClass& other )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        X = other.X;
        Y = other.Y;
        Z = other.Z;

        return *this;
    }

    int X, Y, Z;
};


TestClass CloneTestClass( TestClass& in )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return in;
}


int main()
{
    TestClass tc;
    auto copy = CloneTestClass( tc );
    std::cout << copy.X << std::endl;
    return 0;
}