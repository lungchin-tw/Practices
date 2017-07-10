
#include <iostream>
#include <vector>

class TestClass
{
public:
    TestClass()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    TestClass( int value )
    {
        X.resize( value );
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    TestClass( const TestClass& other )
        : X( other.X )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        *this = other;
    }

    TestClass( const TestClass&& other )
        : X( std::move(other.X) )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    TestClass& operator =( const TestClass& other )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        X = other.X;

        return *this;
    }

    TestClass& operator =( const TestClass&& other )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;

        X = std::move(other.X);

        return *this;
    }

    std::vector<int> X;
};


void SwapTestClass( TestClass& a, TestClass& b )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    TestClass tmp( std::move(a) );
    a = std::move(b);
    b = std::move(tmp);
}


int main()
{
    TestClass tca(1), tcb(2);

    SwapTestClass( tca, tcb );
    std::cout << tca.X.size() << std::endl;
    std::cout << tcb.X.size() << std::endl;
    return 0;
}