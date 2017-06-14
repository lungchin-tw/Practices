/*
** (c) Copyright SOFTSTAR ENTERTAINMENT INC. All Rights Reserved.
*/

#include <iostream>

#include "Poco/Net/DNS.h"

void pocoNetworkPractice()
{
    std::cout << std::endl << "============== " << __PRETTY_FUNCTION__ << " ==============" << std::endl;

    std::string url = "www.apple.com";
    Poco::Net::HostEntry host_entry = Poco::Net::DNS::hostByName( url );

    std::cout << "Information About www.apple.com :\n";
    std::cout << "\t Canonical Name: " << host_entry.name() << std::endl;

    std::cout << "\t Alias Count: " << host_entry.aliases().size() << std::endl;
    for( auto& it : host_entry.aliases()  )
    {
        std::cout << "\t Alias: " << it << std::endl;
    }

    std::cout << "\t Address Count: " << host_entry.addresses().size() << std::endl;
    for( auto& it : host_entry.addresses()  )
    {
        std::cout << "\t Address: " << it.toString() << std::endl;
    }

    std::cout << "===========================================================" << std::endl;
}