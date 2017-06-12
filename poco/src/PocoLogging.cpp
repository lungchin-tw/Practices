
/*
** (c) Copyright SOFTSTAR ENTERTAINMENT INC. All Rights Reserved.
*/

#include <iostream>
#include "PocoLogging.h"
#include "Poco/Logger.h"
#include "Poco/AutoPtr.h"
#include "Poco/SimpleFileChannel.h"


void pocoLoggingPractice()
{
    std::cout << std::endl << "============== " << __PRETTY_FUNCTION__ << " ==============" << std::endl;

    Poco::AutoPtr<Poco::SimpleFileChannel> channel( new Poco::SimpleFileChannel );
    channel->setProperty( "path", "PocoLoggingPractice.log" );

    Poco::Logger& logger = Poco::Logger::create( "PracticeLogger", channel );
    logger.information( "PracticeLogger : Information" );
    logger.warning( "PracticeLogger : Warning" );

    std::cout << "===========================================================" << std::endl;
}