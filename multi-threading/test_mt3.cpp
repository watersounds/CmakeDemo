/*
创建的新线程对当前作用域的变量的使用，
创建新线程的作用域结束后，有可能线程仍然在执行，
这时局部变量随着作用域的完成都已销毁，
如果线程继续使用局部变量的引用或者指针，会出现意想不到的错误，
并且这种错误很难排查。
*/

#include <iostream>
#include <thread>

using namespace std;

// auto fn = [](int *a) {
//     for (int i = 0; i < 10; i++)
//         cout << *a << endl;
// };

int main() 
{
    auto fn = [](int *a) {
    for (int i = 0; i < 10; i++)
        cout << *a << endl;
    };


  [=] {
    int a = 100;

    thread t(fn, &a);

    t.detach();
  }();

  getchar();
  return 0;
}
