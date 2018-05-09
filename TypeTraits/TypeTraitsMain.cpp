

#include <iostream>
#include <typeinfo>


template<class TYPE>
struct TypeTraits
{
    enum { IsPointer = false };
    enum { IsReference = false };
    enum { IsConst = false };
    typedef TYPE Type;
};

template<class TYPE>
struct TypeTraits<TYPE*>
{
    enum { IsPointer = true };
    enum { IsReference = false };
    enum { IsConst = false };
    typedef TYPE Type;
};

template<class TYPE>
struct TypeTraits<TYPE&>
{
    enum { IsPointer = false };
    enum { IsReference = true };
    enum { IsConst = false };
    typedef TYPE Type;
};

template<class TYPE>
struct TypeTraits<const TYPE>
{
    enum { IsPointer = false };
    enum { IsReference = false };
    enum { IsConst = true };
    typedef TYPE Type;
};

template<class TYPE>
struct TypeTraits<const TYPE*>
{
    enum { IsPointer = true };
    enum { IsReference = false };
    enum { IsConst = true };
    typedef TYPE Type;
};

template<class TYPE>
struct TypeTraits<const TYPE&>
{
    enum { IsPointer = false };
    enum { IsReference = true };
    enum { IsConst = true };
    typedef TYPE Type;
};


template< class TYPE >
void PrintTypeTraits()
{
    std::cout 
    << "{ IsPointer : " << TypeTraits<TYPE>::IsPointer
    << ", IsReference : " << TypeTraits<TYPE>::IsReference
    << ", IsConst : " << TypeTraits<TYPE>::IsConst
    << ", Original TypeName : " << typeid( typename TypeTraits<TYPE>::Type ).name()
    << " }";
}

int main()
{
    std::cout << "Int's typename : " << typeid( int ).name() << std::endl;
    std::cout << "Const Int's typename : " << typeid( const int ).name() << std::endl;
    std::cout << "Int*'s typename : " << typeid( int* ).name() << std::endl;
    std::cout << "Const Int*'s typename : " << typeid( const int* ).name() << std::endl;
    std::cout << "Int&'s typename : " << typeid( int& ).name() << std::endl;
    std::cout << "Const Int&'s typename : " << typeid( const int& ).name() << std::endl;
    std::cout << "Float's typename : " << typeid( float ).name() << std::endl;
    std::cout << "Int's TypeTraits : "; PrintTypeTraits<int>(); std::cout << std::endl;
    std::cout << "const Int's TypeTraits : "; PrintTypeTraits<const int>(); std::cout << std::endl;
    std::cout << "Int*'s TypeTraits : "; PrintTypeTraits<int*>(); std::cout << std::endl;
    std::cout << "const Int*'s TypeTraits : "; PrintTypeTraits<const int*>(); std::cout << std::endl;
    std::cout << "Int&'s TypeTraits : "; PrintTypeTraits<int&>(); std::cout << std::endl;
    std::cout << "const Int&'s TypeTraits : "; PrintTypeTraits<const int&>(); std::cout << std::endl;
    
    return 0;
}