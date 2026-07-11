/*
 * 练习3：构造与析构顺序
 *
 * 补全代码，观察构造/析构的输出顺序
 * 预期输出：
 * Base constructor
 * Member constructor
 * Derived constructor
 * Derived destructor
 * Member destructor
 * Base destructor
 */
#include <iostream>
using namespace std;

class Base {
 public:
  Base() { cout << "Base constructor" << endl; }
  // TODO 1: 补全析构函数（输出 "Base destructor"）
  ~Base() { cout << "Base destructor" << endl; }
};

class Member {
 public:
  Member() { cout << "Member constructor" << endl; }
  // TODO 2: 补全析构函数（输出 "Member destructor"）
  ~Member() { cout << "Member destructor" << endl; }
};

class Derived : public Base {
  Member m;  // 对象成员
 public:
  Derived() { cout << "Derived constructor" << endl; }
  // TODO 3: 补全析构函数（输出 "Derived destructor"）
  ~Derived() { cout << "Derived destructor" << endl; }
};

int main() {
  cout << "--- 创建派生类对象 ---" << endl;
  Derived d;
  cout << "--- 对象即将销毁 ---" << endl;
  return 0;
}
