/*
 * 练习5a：运算符重载 - 前置++ / 后置++ / 友元+
 *
 * 补全代码，让程序输出：
 * Metal1: 10 100 1000
 * after ++m: 11 110 1100
 * after m++: 12 121 1210
 * after m1+m2: 11 110 1100
 */
#include <iostream>
using namespace std;

class Metal {
  int hard;    // 硬度
  int volume;  // 体积
 public:
  Metal(int h, int v) : hard(h), volume(v) {}

  // TODO 1: 前置 ++ 成员函数（返回引用，先加后返回）
  // 硬度+1，体积+10%
  Metal& operator++() {
    hard++;
    volume = volume * 1.1;
    return *this;
  }
  // TODO 2: 后置 ++ 成员函数（参数有int占位，先存旧值再加，返回旧值）
  Metal operator++(int) {
    Metal old = *this;
    hard++;
    volume = volume * 1.1;
    return old;
  }
  // TODO 3: 友元 + 重载（两金属合并：硬度和体积各自相加）
  // 提示：friend Metal operator+(const Metal& a, const Metal& b)
  friend Metal operator+(const Metal& obj1, const Metal& obj2) {
    Metal result(0, 0);
    result.hard = obj1.hard + obj2.hard;
    result.volume = obj1.volume + obj2.volume;

    return result;
  }
  void print() { cout << hard << " " << volume << " "; }
};

int main() {
  Metal m(10, 100);
  cout << "metal1:";
  m.print();
  cout << endl;

  cout << "after ++m: ";
  ++m;
  m.print();
  cout << endl;

  cout << "after m++: ";
  m++;
  m.print();
  cout << endl;

  Metal m1(5, 50), m2(6, 60);
  Metal m3 = m1 + m2;
  cout << "after m1+m2: ";
  m3.print();
  cout << endl;

  return 0;
}
