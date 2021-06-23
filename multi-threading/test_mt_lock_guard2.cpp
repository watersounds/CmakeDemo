/*
std::lock_gurad也可以传入两个参数，第一个参数为adopt_lock标识时，表示构造函数中不再进行互斥量锁定，因此此时需要提前手动锁定。
*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;//实例化m对象，不要理解为定义变量
void proc1(int a)
{
    m.lock();//手动锁定
    lock_guard<mutex> g1(m,adopt_lock);
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 2 << endl;
}//自动解锁

void proc2(int a)
{
    lock_guard<mutex> g2(m);//自动锁定
    cout << "proc2函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 1 << endl;
}//自动解锁
int main()
{
    int a = 0;
    thread proc11(proc1, a);
    thread proc21(proc2, a);
    proc11.join();
    proc21.join();
    return 0;
}