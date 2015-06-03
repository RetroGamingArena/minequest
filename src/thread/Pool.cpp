#include <cstdlib>

#include "Pool.h"
// Start of user code includes
#include "Task.h"
// End of user code

Pool::Pool(int _threadCount, bool _running, std::thread* _work, std::mutex* _mutex, bool _started)
{
	threadCount = _threadCount;
	running = _running;
	work = _work;
	mutex = _mutex;
	started = _started;
}

Pool::Pool()
// Start of user code super class
// End of user code
{
	// Start of user code constructor
    running=false;
    started = false;
    mutex=new std::mutex();
	// End of user code
}


// Start of user code methods
// End of user code




int Pool::getThreadCount()
{
	// Start of user code getThreadCount
	// End of user code
	return threadCount;
}

void Pool::setThreadCount(int _threadCount)
{
	threadCount = _threadCount;
}

bool Pool::getRunning()
{
	// Start of user code getRunning
	// End of user code
	return running;
}

void Pool::setRunning(bool _running)
{
	running = _running;
}

std::thread* Pool::getWork()
{
	// Start of user code getWork
	// End of user code
	return work;
}

void Pool::setWork(std::thread* _work)
{
	work = _work;
}

std::mutex* Pool::getMutex()
{
	// Start of user code getMutex
	// End of user code
	return mutex;
}

void Pool::setMutex(std::mutex* _mutex)
{
	mutex = _mutex;
}

bool Pool::getStarted()
{
	// Start of user code getStarted
	// End of user code
	return started;
}

void Pool::setStarted(bool _started)
{
	started = _started;
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
                    //task = pool->buildTask();
                    task = NULL;
                    break;
                }
            }
            
        }
    }
    pool->setStarted(true);
	// End of user code
}
bool Pool::isRunning()
{
	// Start of user code isRunning
    for(int i = 0; i < threads.size(); i++)
    {
        if( threads[i] != NULL )
            if( threads[i]->isBusy() )
            {
                return true;
            }
        /*else
         {
         delete threads[i];
         threads.erase(threads.begin()+i);
         threads.insert(threads.begin()+i, NULL);
         }*/
    }
    return false;
	// End of user code
}

vector<Thread*> Pool::getThreads()
{
	// Start of user code getThreads
	// End of user code
	return threads;
}

void Pool::setThreadsAt(Thread* _threads, int indice)
{
	threads[indice] = _threads;
}

