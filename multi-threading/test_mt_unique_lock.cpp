/* This source file must have a .cpp extension so that all C++ compilers
std::unique_lock类似于lock_guard,只是std::unique_lock用法更加丰富，同时支持std::lock_guard()的原有功能。 使用std::lock_guard后不能手动lock()与手动unlock();使用std::unique_lock后可以手动lock()与手动unlock(); std::unique_lock的第二个参数，除了可以是adopt_lock,还可以是try_to_lock与defer_lock;
*/

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;
void proc1(int a)
{
    unique_lock<mutex> g1(m, defer_lock);//始化了一个没有加锁的mutex
    cout << "xxxxxxxx" << endl;
    g1.lock();//手动加锁，注意，不是m.lock();注意，不是m.lock(),m已经被g1接管了;
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    cout << "现在a为" << a + 2 << endl;
    g1.unlock();//临时解锁
    cout << "xxxxx"  << endl;
    g1.lock();
    cout << "xxxxxx" << endl;
}//自动解锁

void proc2(int a)
{
    unique_lock<mutex> g2(m,try_to_lock);//尝试加锁一次，但如果没有锁定成功，会立即返回，不会阻塞在那里，且不会再次尝试锁操作。
    if(g2.owns_lock()){//锁成功
        cout << "proc2函数正在改写a" << endl;
        cout << "原始a为" << a << endl;
        cout << "现在a为" << a + 1 << endl;
    }else{//锁失败则执行这段语句
        cout <<"default"<<endl;
    }
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


/*
!std::unique_lock所有权的转移

注意，这里的转移指的是std::unique_lock对象间的转移；std::mutex对象的所有权不需要手动转移给std::unique_lock , std::unique_lock对象实例化后会直接接管std::mutex。
mutex m;
{  
    unique_lock<mutex> g2(m,defer_lock);
    unique_lock<mutex> g3(move(g2));//所有权转移，此时由g3来管理互斥量m
    g3.lock();
    g3.unlock();
    g3.lock();
}
*/