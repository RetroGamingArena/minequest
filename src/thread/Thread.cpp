#include <cstdlib>

#include "Thread.h"
// Start of user code includes
// End of user code

Thread::Thread(std::mutex* _mutex)
{
	mutex = _mutex;
}

Thread::Thread()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    mutex = new std::mutex;
	// End of user code
}

Thread::~Thread()
{
	// Start of user code destructor
	// End of user code
}

// Start of user code methods
// End of user code




std::mutex* Thread::getMutex()
{
	return mutex;
}

void Thread::setMutex(std::mutex* _mutex)
{
	mutex = _mutex;
}

void Thread::start()
{
	// Start of user code start
    mutex->lock();
    thread* t = new thread(run, this);
	// End of user code
}
bool Thread::isBusy()
{
	// Start of user code isBusy
    if(mutex->try_lock())
    {
        mutex->unlock();
        return false;
    }
    return true;
	// End of user code
}
void Thread::run(Thread * thread)
{
	// Start of user code run
    if( thread->task != NULL)
    {
        thread->task->run();
        thread->mutex->unlock();
    }
	// End of user code
}

Task* Thread::getTask()
{
	// Start of user code getTask
	// End of user code
	return task;
}

void Thread::setTask(Task* _task)
{
	task = _task;
}
					
