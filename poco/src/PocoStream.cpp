
#include <iostream>
#include "PocoStream.h"
#include "Poco/Base64Encoder.h"

void pocoStreamPractice()
{
    std::cout << std::endl << "============== " << __PRETTY_FUNCTION__ << " ==============" << std::endl;
    
    Poco::Base64Encoder encoder( std::cout );
    std::cout << "Base64Encoder \"Hello Base64Encoder.\" : ";
    encoder << "Hello Base64Encoder" << std::endl;
}