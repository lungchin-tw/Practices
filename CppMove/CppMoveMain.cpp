
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
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        *this = other;
    }

    TestClass( const TestClass&& other )
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        *this = std::move( other );
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


void TransferObjectByValue( const TestClass a, const TestClass b )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::cout << a.X.size() << std::endl;
    std::cout << b.X.size() << std::endl;
}

void TransferObjectByRef( const TestClass& a, const TestClass& b )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::cout << a.X.size() << std::endl;
    std::cout << b.X.size() << std::endl;
}

void SwapTestClassByRef( TestClass& a, TestClass& b )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    TestClass tmp( std::move(a) );
    a = std::move(b);
    b = std::move(tmp);
}


int main()
{
    TestClass tca(1), tcb(2);

    std::cout << std::endl << "Pre TransferObjectByValue" << std::endl;
    TransferObjectByValue( tca, tcb );
    
    std::cout << std::endl << "Pre TransferObjectByRef" << std::endl;
    TransferObjectByRef( tca, tcb );

    std::cout << std::endl << "Pre SwapTestClassByRef" << std::endl;
    SwapTestClassByRef( tca, tcb );

    std::cout << std::endl << tca.X.size() << std::endl;
    std::cout << tcb.X.size() << std::endl;
    return 0;
}