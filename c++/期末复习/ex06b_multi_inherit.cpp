/*
 * 练习6b：继承方式 + 多重继承构造顺序
 *
 * 补全代码，让程序输出（注意顺序）：
 * A constructor
 * B constructor
 * C constructor
 * D constructor
 * D destructor
 * C destructor
 * B destructor
 * A destructor
 */
#include <iostream>
using namespace std;

class A {
 public:
  A() { cout << "A constructor" << endl; }
  ~A() { cout << "A destructor" << endl; }
};

class B {
 public:
  B() { cout << "B constructor" << endl; }
  ~B() { cout << "B destructor" << endl; }
};

class C {
 public:
  C() { cout << "C constructor" << endl; }
  ~C() { cout << "C destructor" << endl; }
};

// TODO 1: 补全 D 类，让它同时继承 A, B, C
// 关键是看构造顺序——取决于继承列表的顺序还是别的东西
class D : public A, public B, public C {
 public:
  D() { cout << "D constructor" << endl; }
  ~D() { cout << "D destructor" << endl; }
};

int main() {
  D d;
  return 0;
}
