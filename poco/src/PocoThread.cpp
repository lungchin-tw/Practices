/*
** (c) Copyright SOFTSTAR ENTERTAINMENT INC. All Rights Reserved.
*/

#include <iostream>

#include "Poco/Thread.h"
#include "Poco/ThreadPool.h"
#include "Poco/ThreadLocal.h"
#include "Poco/Runnable.h"
#include "Poco/RunnableAdapter.h"


class AngleRunnable : public Poco::Runnable
{
    virtual void run()
    {
        for( *_counter = 0; *_counter < 10; ++(*_counter) )
        {
            std::cout << __PRETTY_FUNCTION__ << *_counter << std::endl;
        }
    }

private:
    Poco::ThreadLocal<int> _counter;
};


class DiabloPuppet
{
public:
    void shout()
    {
        for( *_counter = 0; *_counter < 10; ++(*_counter) )
        {
            std::cout << __PRETTY_FUNCTION__ << *_counter << std::endl;
        }
    }

private:
    Poco::ThreadLocal<int> _counter;
};

void pocoThreadPractice()
{
    std::cout << std::endl << "============== " << __PRETTY_FUNCTION__ << " ==============" << std::endl;

    AngleRunnable angle_runnable;

    DiabloPuppet diable_puppet;
    Poco::RunnableAdapter<DiabloPuppet> diablo_runnable( diable_puppet, &DiabloPuppet::shout );

    Poco::Thread angle_thread;
    Poco::Thread diablo_thread;

    angle_thread.start( angle_runnable );
    diablo_thread.start( diablo_runnable );

    diablo_thread.join();
    angle_thread.join();

    std::cout << "===========================================================" << std::endl;
    std::cout << "======== Using Thread Pool ============" << std::endl;

    Poco::ThreadPool::defaultPool().start( diablo_runnable );
    Poco::ThreadPool::defaultPool().start( angle_runnable );
    Poco::ThreadPool::defaultPool().joinAll();

    std::cout << "===========================================================" << std::endl;
}