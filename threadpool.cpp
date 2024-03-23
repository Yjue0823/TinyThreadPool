#include "threadpool.h"

const int TASK_QUE_MAX_SIZE = 1024;

ThreadPool::ThreadPool()
    :initThreadSize_(4),
     taskSize_(0),
     taskQueMaxThreshold_(TASK_QUE_MAX_SIZE),
     mode_(ThreadPoolMode::FIXED_MODE)
{
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::start()
{
}

void ThreadPool::setThreadSize(int size)
{
}

void ThreadPool::setThreadPoolMode(ThreadPoolMode mode)
{
}

void ThreadPool::setTaskQueSize(int size)
{
}

void ThreadPool::submitTask(std::shared_ptr<Task> sp)
{
}
