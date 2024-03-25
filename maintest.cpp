#include <iostream>
#include "threadpool.h"

class MyTask : public Task{
public:
    void run() override{
        std::cout << "Thread ID:" << std::this_thread::get_id() << " is BEGIN!" << std::endl;
        std::chrono::seconds(3);
        std::cout << "Thread ID:" << std::this_thread::get_id() << " is END!" << std::endl;
    };
};

int main(){
    
    ThreadPool pool;    
    pool.start(4);

    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    getchar();
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());
    pool.submitTask(std::make_shared<MyTask>());

    getchar();
    return 0;
}