/* This source file must have a .cpp extension so that all C++ compilers
向线程传递参数
在线程内，将对象的字段a和b设置为新的值，但是在线程调用结束后，这两个字段的值并不会改变。
这样由于引用的实际上是局部变量node的一个拷贝，而不是node本身。在将对象传入线程的时候，
调用std::ref，将node的引用传入线程，而不是一个拷贝。
thread t(func,std::ref(node));
*/

#include <iostream>
#include <thread>

using namespace std;

class _tagNode {
public:
  int a;
  int b;
};

void func(_tagNode& node) {
  cout << node.a << endl;
  cout << node.b << endl;
  node.a = 10;
  node.b = 20;
}

void f() {
  _tagNode node;
  // thread t(func, node);
  thread t(func, std::ref(node));
  cout << "id: " << t.get_id() << endl;
  t.join();

  printf("\n\n===================\n\n");

  cout << node.a << endl;
  cout << node.b << endl;
}

int main() {
  f();
  return 0;
}