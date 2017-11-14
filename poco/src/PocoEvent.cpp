

#include <iostream>

#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"


class TestEventSender
{
public:
    Poco::BasicEvent<const int> TheEvent;
};


class TestTarget
{
public:
    void OnReceivedEvent( const void* sender, const int& arg )
    {
        std::cout << std::endl << "============== " << __PRETTY_FUNCTION__ << ", Arg=" << arg << " ==============" << std::endl;
    }
};


void PocoEventPractice()
{
    std::cout << std::endl << "============== " << __PRETTY_FUNCTION__ << " ==============" << std::endl;

    TestEventSender event_sender;
    TestTarget target;

    event_sender.TheEvent += Poco::delegate( &target, &TestTarget::OnReceivedEvent );
    event_sender.TheEvent.notify( &event_sender, 10 );
}