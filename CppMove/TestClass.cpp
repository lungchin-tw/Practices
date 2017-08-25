
#include <vector>
#include <iostream>
#include <utility>

class TestClass
{
public:
    TestClass();
    TestClass( int value );
    TestClass( const TestClass& other );
    TestClass( const TestClass&& other );
    TestClass& operator =( const TestClass& other );
    TestClass& operator =( const TestClass&& other );

    std::vector<int> X;
};

TestClass::TestClass()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

TestClass::TestClass( int value )
{
    X.resize( value );
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

TestClass::TestClass( const TestClass& other )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    *this = other;
}

TestClass::TestClass( const TestClass&& other )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    *this = std::move( other );
}

TestClass& TestClass::operator =( const TestClass& other )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    X = other.X;

    return *this;
}

TestClass& TestClass::operator =( const TestClass&& other )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    X = std::move(other.X);

    return *this;
}

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

void operator+=( TestClass& x, TestClass const& y )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

/*TestClass operator+( TestClass const& x, TestClass const& y )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    TestClass result( x );
    result += y;
    return result;
}*/

TestClass operator+( TestClass x, TestClass const& y )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    x += y;
    TestClass temp;
    std::swap( x, temp );
    return temp;
}