/*
不推荐实直接去调用成员函数lock()，因为如果忘记unlock()，将导致锁无法释放，使用lock_guard或者unique_lock则能避免忘记解锁带来的问题。
其原理是：声明一个局部的std::lock_guard对象，在其构造函数中进行加锁，在其析构函数中进行解锁。最终的结果就是：创建即加锁，作用域结束自动解锁。从而使用std::lock_guard()就可以替代lock()与unlock()。

*/
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;//实例化m对象，不要理解为定义变量
void proc1(int a)
{
    lock_guard<mutex> g1(m);//用此语句替换了m.lock()；lock_guard传入一个参数时，该参数为互斥量，此时调用了lock_guard的构造函数，申请锁定m
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 2 << endl;
}//此时不需要写m.unlock(),g1出了作用域被释放，自动调用析构函数，于是m被解锁

void proc2(int a)
{
    {
        lock_guard<mutex> g2(m);
        cout << "proc2函数正在改写a" << endl;
        cout << "原始a为" << a << endl;
        cout << "现在a为" << a + 1 << endl;
    }//通过使用{}来调整作用域范围，可使得m在合适的地方被解锁
    cout << "作用域外的内容3" << endl;
    cout << "作用域外的内容4" << endl;
    cout << "作用域外的内容5" << endl;
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