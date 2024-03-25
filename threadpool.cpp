#include "threadpool.h"

const int TASK_QUE_MAX_SIZE = 4;
/**
 * @brief 线程池构造函数
 */
ThreadPool::ThreadPool()
    :initThreadSize_(4),
     taskSize_(0),
     taskQueMaxThreshold_(TASK_QUE_MAX_SIZE),
     mode_(ThreadPoolMode::FIXED_MODE)
{

}
/**
 * @brief 线程池析构函数
 */
ThreadPool::~ThreadPool()
{

}

/**
 * @brief 线程池模型中 threadFunc作为线程函数 主要的操作职能是作为 消费者
 * @brief 消费 task 队列
 * @brief 条件变量和互斥锁
 */
void ThreadPool::threadFunc()
{
    // for(;;) // 子线程中进行的死循环
    {
        std::shared_ptr<Task> task;
        {
            // 先获取锁
            std::unique_lock<std::mutex> lock(taskQueMtx_);

            // 等待notEmpty_条件
            notEmpty_.wait(lock, [=]()->bool{
                return taskQue_.size() > 0;
            });

            // 从任务队列中取一个任务出来
            task = taskQue_.front();
            taskQue_.pop();
            taskSize_--;
            std::cout << "线程ID:" << std::this_thread::get_id() <<"成功获取任务" << std::endl;

            if( taskQue_.size() > 0){
                notEmpty_.notify_all();
            }

            notFull_.notify_all();
        } // 锁的释放

        // 当前线程负责执行这个任务
        if(task != nullptr){task->run();}      
    }
}

/**
 * @brief  线程池启动入口 初始化Thread线程类 
 * @param  initThreadSize   My Param doc
 */
void ThreadPool::start(int initThreadSize)
{
    // 记录线程的初始个数
    this->initThreadSize_ = initThreadSize;

    // 初始化 Thread类
    for(int i = 0; i < initThreadSize_; i++){
        auto ptr = std::make_shared<Thread>(std::bind(&ThreadPool::threadFunc, this));
        this->threadList_.emplace_back(ptr);
        /*  
            如果这个地方使用的一个 unique_ptr<> 注意 unique_ptr是不允许进行拷贝构造的 他只有右值引用
            所以如果要往容器中置入的话 一定要考虑一下这个拷贝构造的问题 这个地方应该使用移动语义！
            auto ptr = std::make_unique<Thread>(std::bind(&ThreadPool::threadFunc, this));
            this->threadList_.emplace_back(std::move(ptr));
        */
    }

    // Thread类 线程启动
    for(int i = 0; i < initThreadSize_; i++){
        this->threadList_[i]->start();
    }
}

/**
 * @brief  设置线程池的工作模式 
 * @param  mode ThreadPoolMode枚举类
 */
void ThreadPool::setThreadPoolMode(ThreadPoolMode mode)
{
    this->mode_ = mode;
}

/**
 * @brief 设置任务队列的长度
 * @param  size My Param doc
 */
void ThreadPool::setTaskQueSize(int size)
{

}

/**
 * @brief  任务提交接口 用于提交任务
 * @brief  给线程池提交任务 用户调用接口 传入任务对象
 * @param  sp 传入的是一个智能指针 由于这个结构是暴露给使用者的 考虑到会传入一个临时对象 导致直接析构 所以传一个智能指针
 */
void ThreadPool::submitTask(std::shared_ptr<Task> sp)
{
    // 获取锁
    std::unique_lock<std::mutex> lock(this->taskQueMtx_);

    // 线程的通信 等待任务队列有空余
    // while(taskQue_.size() == TASK_QUE_MAX_SIZE)
    // {
    //     notFull_.wait(lock);
    // }
    if(!notFull_.wait_for(lock, std::chrono::seconds(1),
    [=]()->bool {
        return taskQue_.size() < TASK_QUE_MAX_SIZE;
    }))
    {
        std::cerr << "TaskQue is Full, Submit Task is Error!" << std::endl;
        return ;
    }
    // C++11 写法
    // notFull_.wait(lock, [=]()->bool{
    //     return taskQue_.size() < TASK_QUE_MAX_SIZE;
    // });
    // 如果有空余 把任务放入任务队列中
    taskQue_.emplace(sp);
    taskSize_++;

    // 新放了任务，任务队列肯定不空了，在notEmpty_上进行通知
    notEmpty_.notify_all();
}


/* ——————————————————线程类的相关实现—————————————————— */
/**
 * @brief Construct a new Thread:: Thread object
 * @param  func 传入的是一个函数指针 --std::bind --std::function
 */
Thread::Thread(ThreadFunc func):func_(func)
{
}
/**
 * @brief 线程类析构函数
 */
Thread::~Thread()
{
}
/**
 * @brief 线程对象 启动入口 主要职责是启动线程对象的函数 进入子线程工作
 */
void Thread::start()
{
    std::thread t(func_);
    t.detach(); // 线程对象 在出作用域时就会被析构 所以需要子线程分离
}
