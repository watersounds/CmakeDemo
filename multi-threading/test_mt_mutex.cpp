/* This
互斥量（锁）,   需要在进入临界区之前对互斥量加锁，退出临界区时对互斥量解锁；
*/
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m; //
void proc1(int a)
{
    m.lock();
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 2 << endl;
    m.unlock();
}

void proc2(int a)
{
    m.lock();
    cout << "proc2函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 1 << endl;
    m.unlock();
}

int main()
{
    int a = 0;
    thread proc11(proc1, a);
    thread proc21(proc2, a);
    proc11.join();
    proc21.join();
    return 0;
}
