
#include <iostream>
#include <algorithm>

#include "CodeBoilerplate.h"


class XClass
{
public:
    ~XClass()
    {
        std::cout << FUNCTION_NAME << std::endl;
    }
};


int main()
{
    std::unique_ptr<XClass> x = std::make_unique<XClass>(); 
    x = std::make_unique<XClass>();
    
    return 0;
}