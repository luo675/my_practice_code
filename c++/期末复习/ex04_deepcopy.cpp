/*
 * 练习4：深拷贝 vs 浅拷贝
 *
 * 补全拷贝构造函数和赋值运算符，实现深拷贝
 * 预期输出（无乱码/无重复释放）：
 * 100 200 300
 * 400 500 600
 */
#include <iostream>
using namespace std;

class Array {
  int* data;
  int size;

 public:
  Array(int s) : size(s) { data = new int[size]; }

  // TODO 1: 补全析构函数（释放 data）
  ~Array() { delete[] data; }
  // TODO 2: 补全拷贝构造函数（深拷贝）
  Array(const Array& obj) {
    size = obj.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = obj.data[i];
    }
  }
  // TODO 3: 补全赋值运算符（深拷贝，防自赋值）
  Array& operator=(const Array& other) {
    // 你的代码
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = other.data[i];
    }
    return *this;
  }

  void set(int index, int value) { data[index] = value; }
  int get(int index) { return data[index]; }
};

int main() {
  Array arr1(3);
  arr1.set(0, 100);
  arr1.set(1, 200);
  arr1.set(2, 300);

  Array arr2 = arr1;  // 调用拷贝构造
  for (int i = 0; i < 3; i++) cout << arr2.get(i) << " ";
  cout << endl;

  Array arr3(3);
  arr3 = arr1;  // 调用赋值运算符
  for (int i = 0; i < 3; i++) cout << arr3.get(i) << " ";
  cout << endl;

  return 0;
  // 三个对象析构，不能重复释放
}
