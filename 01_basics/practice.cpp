#include <iostream>

class A {
 public:
  A(int v) : x(v) {}

  // 1️⃣ 返回普通值
  int getXByValue() const { return x; }

  // 2️⃣ 返回引用（非 const，危险）
  int& getXByRef() { return x; }

  // 3️⃣ 返回 const 引用（推荐）
  const int& getXByConstRef() const { return x; }

  void printAddress() const { std::cout << "x address: " << &x << std::endl; }

 private:
  int x;
};

int main() {
  A a(10);

  std::cout << "=== 返回普通值 ===" << std::endl;
  int v = a.getXByValue();
  std::cout << "v = " << v << std::endl;

  std::cout << "\n=== 返回引用（非 const）===" << std::endl;
  a.getXByRef() = 20;  // ✅ 直接修改内部 x
  std::cout << "after modify: " << a.getXByValue() << std::endl;

  std::cout << "\n=== 返回 const 引用 ===" << std::endl;
  const int& r = a.getXByConstRef();
  std::cout << "r = " << r << std::endl;

  // ❌ 下面这行如果取消注释，会编译错误
  // a.getXByConstRef() = 30;

  std::cout << "\n=== 地址观察 ===" << std::endl;
  a.printAddress();
  std::cout << "r address: " << &r << std::endl;

  return 0;
}