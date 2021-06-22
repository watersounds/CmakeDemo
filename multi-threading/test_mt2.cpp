/* This source file must have a .cpp extension so that all C++ compilers
使用重载了()运算符的类实现多线程数字输出
*/
#include <iostream>
#include <thread>

using namespace std;
class Task
{
    public:
    void operator()(int i)
    {
        cout << i << endl;
    }
};

int main()
{
    for (uint8_t i = 0; i < 4; i++)
    {
        // Task task;
        // thread t(task, i);

        /*
        把函数对象传入std::thread的构造函数时，
        要注意一个C++的语法解析错误（C++'s most vexing parse）。
        向std::thread的构造函数中传入的是一个临时变量，
        而不是命名变量就会出现语法解析错误。如下代码：
        std::thread t(Task());  
        这里相当于声明了一个函数t，其返回类型为thread，而不是启动了一个新的线程。
        */

        //可以使用新的初始化语法避免这种情况
        thread t{Task(), i};
        t.detach();
    }

    getchar();
	return 0;
}