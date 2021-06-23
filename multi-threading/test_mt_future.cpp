#include <unistd.h>
// linux: unistd.h   windows:  windows.h
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
double t1(const double a, const double b) {
  double c = a + b;
  //   usleep(9000); //假设t1函数是个复杂的计算过程，需要消耗3秒
  sleep(3);
  return c;
}

int main() {
  double a = 2.3;
  double b = 6.7;
  future<double> fu =
      async(t1, a, b); //创建异步线程线程，并将线程的执行结果用fu占位；
  cout << "正在进行计算" << endl;
  cout << "计算结果马上就准备好，请您耐心等待" << endl;
  cout << "计算结果：" << fu.get() << endl; //阻塞主线程，直至异步线程return
  try {
    cout << "计算结果：" << fu.get() << endl;
  } catch (...) {
      cout << "catch (...)" << endl; 
  }
  // 取消该语句注释后运行会报错，因为future对象的get()方法只能调用一次。

  a = 3.3;
  b = 6.7;
  shared_future<double> s_fu =
      async(t1, a, b); //创建异步线程线程，并将线程的执行结果用fu占位；
  cout << "正在进行计算" << endl;
  cout << "计算结果马上就准备好，请您耐心等待" << endl;
  cout << "计算结果：" << s_fu.get() << endl; //阻塞主线程，直至异步线程return
  cout << "=========" << endl;
  cout << "计算结果：" << s_fu.get() << endl;

  return 0;
}