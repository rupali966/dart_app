#include <iostream>
#include <thread>
class thread_guard{
    std::thread& t;
    public: 
    explicit thread_guard(std::thread& t_):t(t_){}
    ~thread_guard(){
        if (t.joinable())
        {
            t.join();
        }
        
    }
    thread_guard(thread_guard const&)=delete;
    thread_guard& operator=(thread_guard const&)=delete;

};
struct func{
    int & i;
    func(int& i_):i(i_){}
    void operator() (){
        for(unsigned j=0;j<1000000;j++){
            std::cout<<i;
        }
    }
};

int main()
{
    int some_local_state =0;
    func my_fun(some_local_state);
    std::thread t(my_fun);
    thread_guard g(t);
    std::cout << "Thread is running ...\n";

    return 0;
}