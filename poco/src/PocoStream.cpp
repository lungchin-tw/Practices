
#include <iostream>
#include <fstream>

#include "PocoStream.h"
#include "Poco/Base64Encoder.h"
#include "Poco/TeeStream.h"
#include "Poco/LocalDateTime.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/DateTimeFormatter.h"

void pocoStreamPractice()
{
    std::cout << std::endl << "============== " << __PRETTY_FUNCTION__ << " ==============" << std::endl;

    Poco::TeeOutputStream tee( std::cout );
    std::ofstream fstr( "pocoStreamPractice.log" );
    tee.addStream( fstr );

    Poco::LocalDateTime local_now;
    tee 
    << "["
    << Poco::DateTimeFormatter::format( local_now, Poco::DateTimeFormat::SORTABLE_FORMAT ) 
    << "]"
    << " Hello, Poco TeeOutputStream"
    << std::endl;

    Poco::Base64Encoder encoder( std::cout );
    std::cout << "Base64Encoder \"Hello Base64Encoder.\" : ";
    encoder << "Hello Base64Encoder" << std::endl;
}