
#include <iostream>
#include "Poco/Environment.h"
#include "Poco/DateTime.h"
#include "Poco/LocalDateTime.h"
#include "Poco/DateTimeParser.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/Timezone.h"

using namespace Poco;

int main()
{
    std::cout << "Hello, STN( Softstar Network )." << std::endl;
    std::cout << std::endl << "========== System Information ==========" << std::endl;

    #if defined( POCO_OS_FAMILY_VMS )
        std::cout << "POCO_OS_FAMILY_VMS" << std::endl;
    #endif

    #if defined( POCO_OS_FAMILY_UNIX )
        std::cout << "POCO_OS_FAMILY_UNIX" << std::endl;
    #endif

    #if POCO_OS == POCO_OS_MAC_OS_X
        std::cout << "POCO_OS == POCO_OS_MAC_OS_X" << std::endl;
    #endif

    #if defined( POCO_ARCH_LITTLE_ENDIAN )
        std::cout << "POCO_ARCH_LITTLE_ENDIAN" << std::endl;
    #endif

    #if defined( POCO_ARCH_BIG_ENDIAN )
        std::cout << "POCO_ARCH_BIG_ENDIAN" << std::endl;
    #endif

    #if defined( POCO_COMPILER_CLANG )
        std::cout << "POCO_COMPILER_CLANG" << std::endl;
    #endif

    #if defined( POCO_COMPILER_GCC )
        std::cout << "POCO_COMPILER_GCC" << std::endl;
    #endif

    std::cout << "OS Name:" << Environment::osName() << std::endl;
    std::cout << "OS Display Name:" << Environment::osDisplayName() << std::endl;
    std::cout << "OS Version:" << Environment::osVersion() << std::endl;
    std::cout << "OS Architecture:" << Environment::osArchitecture() << std::endl;
    std::cout << "Node Name:" << Environment::nodeName() << std::endl;
    std::cout << "Node ID:" << Environment::nodeId() << std::endl;
    std::cout << "Processor Count:" << Environment::processorCount() << std::endl;
    std::cout << "Poco LibraryVersion:" << Environment::libraryVersion() << std::endl;

    std::cout << "=======================================" << std::endl;

    std::string datetimestr;
    
    
    std::cout << std::endl << "========== System Time Information ==========" << std::endl;
    std::cout << "Timezone Name:" << Timezone::name() << std::endl;
    std::cout << "Timezone StandardName:" << Timezone::standardName() << std::endl;
    std::cout << "Timezone Daylight Saving Time name:" << Timezone::dstName() << std::endl;

    DateTime now;
    datetimestr = DateTimeFormatter::format( now, DateTimeFormat::SORTABLE_FORMAT );
    std::cout << "Date Time:" << datetimestr << std::endl;

    LocalDateTime local_now;
    datetimestr = DateTimeFormatter::format( local_now, DateTimeFormat::SORTABLE_FORMAT );
    std::cout << "Local Date Time:" << datetimestr << std::endl;

    std::cout << "=======================================" << std::endl;

    

    return 0;
}