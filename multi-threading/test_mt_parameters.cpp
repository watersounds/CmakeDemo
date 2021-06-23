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

/*
!也可以使用类的成员函数作为线程函数，示例如下
class _tagNode{

public:
    void do_some_work(int a);
};
_tagNode node;

thread t(&_tagNode::do_some_work, &node,20);
上面创建的线程会调用node.do_some_work(20)，第三个参数为成员函数的第一个参数，以此类推。
*/


// !转移线程的所有权

// thread是可移动的(movable)的，但不可复制(copyable)。
// 可以通过move来改变线程的所有权，灵活的决定线程在什么时候join或者detach。
// thread t1(f1);
// thread t3(move(t1));