#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <atomic>

// 线程模型
enum class ThreadPoolMode{
    FIXED_MODE,
    CACHE_MODE,
};

// 线程池 任务提交的基类 抽象类
class Task{
public:
    virtual void run() = 0;
private:
};

// 线程池 工作线程的封装
class Thread{
public:
private:
};

// 线程池类型
class ThreadPool{
public:
    // 线程池构造
    ThreadPool();
    // 线程池析构
    ~ThreadPool();
    ThreadPool(const ThreadPool& pool) = delete; // 拷贝构造函数 我们用不着 删掉他！ 留着默认构造 用错了会出问题
    ThreadPool& operator=(const Thread& pool) = delete;

    // 线程池启动
    void start();

    // 设置线程池的线程数量
    void setThreadSize(int size);

    // 线程池工作模式的设置
    void setThreadPoolMode(ThreadPoolMode mode);

    // 线程池task任务队列的数量上限
    void setTaskQueSize(int size);

    // 线程池任务提交接口 对外暴露的 
    void submitTask(std::shared_ptr<Task> sp);

private:
    // 线程容器
    std::vector<Thread*> threadList_;
    int initThreadSize_;

    // 任务队列
    std::queue<std::shared_ptr<Task>> taskQue_;
    std::atomic_int taskSize_;
    int taskQueMaxThreshold_;

    // 线程模式 fixed cached
    ThreadPoolMode mode_;

    // 线程互斥 线程通信
    std::mutex taskQueMtx_;
    std::condition_variable notFull_;
    std::condition_variable notEmpty_;
};