#include <cstdlib>

#include "Pool.h"
// Start of user code includes
#include "Task.h"
// End of user code

Pool::Pool(int _threadCount, bool _running, std::thread* _work, std::mutex* _mutex)
{
	threadCount = _threadCount;
	running = _running;
	work = _work;
	mutex = _mutex;
}

Pool::Pool()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
	// End of user code
}

// Start of user code methods
// End of user code




int Pool::getThreadCount()
{
	return threadCount;
}

void Pool::setThreadCount(int _threadCount)
{
	threadCount = _threadCount;
}
bool Pool::getRunning()
{
	return running;
}

void Pool::setRunning(bool _running)
{
	running = _running;
}
std::thread* Pool::getWork()
{
	return work;
}

void Pool::setWork(std::thread* _work)
{
	work = _work;
}
std::mutex* Pool::getMutex()
{
	return mutex;
}

void Pool::setMutex(std::mutex* _mutex)
{
	mutex = _mutex;
}

void Pool::start()
{
	// Start of user code start
    for(int i = 0; i < threadCount; i++)
    {
        Task* task = buildTask();
        if(task != NULL)
        {
            Thread* thread = new Thread();
            thread->setTask(task);
            threads.push_back(thread);
        }
    }
    for(int i = 0; i < threads.size(); i++)
    {
        Thread* thread = threads[i];
        if(thread != NULL)
            thread->start();
    }
    work = new thread(Pool::run, this);
	// End of user code
}
void Pool::run(Pool * pool)
{
	// Start of user code run
    while (pool->hasNext())
    {
        Task* task = pool->buildTask();
        while(task != NULL )
        {
            for(int i = 0; i < pool->threadCount; i++)
            {
                if( !pool->threads[i]->isBusy() )
                {
                    pool->threads[i]->setTask(task);
                    pool->threads[i]->start();
                    task = pool->buildTask();
                    break;
                }
            }
        }
    }
	// End of user code
}

vector<Thread*> Pool::getThreads()
{
	// Start of user code getThreads
	// End of user code
	return threads;
}

