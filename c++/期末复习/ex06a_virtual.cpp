/*
 * 练习6a：虚函数多态 + 虚析构
 *
 * 补全代码，让程序输出：
 * Animal speaking...
 * Dog: Woof!
 * Cat: Meow!
 * Cat destroyed
 * Animal destroyed
 * Dog destroyed
 * Animal destroyed
 */
#include <iostream>
using namespace std;

class Animal {
 public:
  // TODO 1: 写虚函数 speak()，输出 "Animal speaking..."
  virtual void speak() { cout << "Animal speaking..." << endl; }
  // TODO 2: 写虚析构函数，输出 "Animal destroyed"
  virtual ~Animal() { cout << "Animal destroyed" << endl; }
};

class Dog : public Animal {
 public:
  // TODO 3: 重写 speak()，输出 "Dog: Woof!"
  void speak() { cout << "Dog: Woof!" << endl; }
  // TODO 4: 析构函数，输出 "Dog destroyed"
  ~Dog() { cout << "Dog destroyed" << endl; }
};

class Cat : public Animal {
 public:
  // TODO 5: 重写 speak()，输出 "Cat: Meow!"
  void speak() { cout << "Cat: Meow!" << endl; }
  // TODO 6: 析构函数，输出 "Cat destroyed"
  ~Cat() { cout << "Cat destroyed" << endl; }
};

int main() {
  cout << "Animal speaking..." << endl;

  Animal* p = new Dog();
  p->speak();  // 会发生多态吗？
  p = new Cat();
  p->speak();  // 会发生多态吗？

  delete p;  // 如果没有虚析构会发生什么？
  p = new Dog();
  delete p;

  return 0;
}
