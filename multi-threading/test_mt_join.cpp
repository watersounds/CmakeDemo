/* This source file must have a .cpp extension so that all C++ compilers
异常情况下等待线程完成
*/

#include <iostream>
#include <thread>

using namespace std;

class thread_guard{
    thread &t;
public:
    explicit thread_guard(thread & _t):
    t(_t) {}

    ~thread_guard()
    {
        if (t.joinable()) {
            t.join();
        }
    }

    thread_guard(const thread_guard&) = delete;
    thread_guard& operator=(const thread_guard&) = delete;
};

void func()
{
    thread t([]{
        cout << "Hello thread" << endl;
    });
    t.join();

    thread_guard g(t);
}

int main()
{
    func();
    return 0;
}