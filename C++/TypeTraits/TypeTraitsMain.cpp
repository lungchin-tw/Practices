

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

template< class TYPE >
void PrintTypeInfo()
{
    std::cout 
    << "{ HashCode : " << typeid( TYPE ).hash_code()
    << ", Name : " << typeid( TYPE ).name()
    << " }";
}

int main()
{
    std::cout << "Int : TypeInfo=";  PrintTypeInfo<int>(); std::cout << ", TypeTraits="; PrintTypeTraits<int>(); std::cout << std::endl;
    std::cout << "const Int : TypeInfo=";  PrintTypeInfo<const int>(); std::cout << ", TypeTraits="; PrintTypeTraits<const int>(); std::cout << std::endl;
    std::cout << "int* : TypeInfo=";  PrintTypeInfo<int*>(); std::cout << ", TypeTraits="; PrintTypeTraits<int*>(); std::cout << std::endl;
    std::cout << "int** : TypeInfo=";  PrintTypeInfo<int**>(); std::cout << ", TypeTraits="; PrintTypeTraits<int**>(); std::cout << std::endl;
    std::cout << "const int* : TypeInfo=";  PrintTypeInfo<const int*>(); std::cout << ", TypeTraits="; PrintTypeTraits<const int*>(); std::cout << std::endl;
    std::cout << "const int** : TypeInfo=";  PrintTypeInfo<const int**>(); std::cout << ", TypeTraits="; PrintTypeTraits<const int**>(); std::cout << std::endl;
    std::cout << "int& : TypeInfo=";  PrintTypeInfo<int&>(); std::cout << ", TypeTraits="; PrintTypeTraits<int&>(); std::cout << std::endl;
    std::cout << "const int& : TypeInfo=";  PrintTypeInfo<const int&>(); std::cout << ", TypeTraits="; PrintTypeTraits<const int&>(); std::cout << std::endl;
    
    return 0;
}