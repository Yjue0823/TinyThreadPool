#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>

// Any 类型

class Any{
public:
    Any() = default;
    ~Any() = default;
    // 因为该类成员是一个unique_ptr是没有拷贝构造和赋值的 所以要记得删掉 同时增加默认移动构造函数
    Any(const Any& any) = delete;
    Any& operator=(const Any& any) = delete;
    Any(Any&& any) = default;
    Any& operator=(Any&& any) = default;

    template<typename T>
    Any(T data) : base_(std::make_unique<Any::Deviren<T>>(data)){}
    // Any类的类成员对象是一个unique_ptr智能指针
    template<typename T>
    T cast_(){
        // 从driven_ptr中找到它所指的Driven对象，从他里面读取data成员变量
        Any::Deviren<T> *pd = dynamic_cast<Any::Deviren<T>*>(base_.get());
        if(pd == nullptr){
            throw "type is not match!";
        }
        return pd->data_;
    }
private:
    // 基类类型
    class Base{
    public:
        virtual ~Base() = default;
    };
    template<typename T>
    class Deviren : public Base{
    public:
        Deviren(T data): data_(data){}
        T data_;
    };
private:
    std::unique_ptr<Base> base_; // 基类指针指向派生类对象--》多态
};

// 线程模型
enum class ThreadPoolMode{
    FIXED_MODE,
    CACHE_MODE,
};

// 线程池 任务提交的基类 抽象类
class Task{
public:
    virtual Any run() = 0;
private:
};

// 线程池 工作线程的封装
class Thread{
public:
    using ThreadFunc = std::function<void()>;
    // Thread类 构造函数
    Thread(ThreadFunc func); // 传入一个函数来构造我们的线程池中的 线程类
    ~Thread();

    // 线程函数启动入口
    void start();

private:
    ThreadFunc func_;
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
    void start(int initThreadSize = 4);

    // 设置线程池的线程数量
    // void setThreadSize(int size);

    // 线程池工作模式的设置
    void setThreadPoolMode(ThreadPoolMode mode);

    // 线程池task任务队列的数量上限
    void setTaskQueSize(int size);

    // 线程池任务提交接口 对外暴露的 
    void submitTask(std::shared_ptr<Task> sp);

private:
    // 线程池使用的函数
    void threadFunc();

private:
    // 线程容器
    std::vector<std::shared_ptr<Thread>> threadList_;
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