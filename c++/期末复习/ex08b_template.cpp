/*
 * 练习8b：函数模板 + 类模板
 *
 * 老师原话："模板会考一道题，函数模板和类模板结合在一起考"
 * 对应模拟题⑩加密模板
 *
 * 补全代码，让程序输出：
 * 5
 * 3.3
 * c
 */
#include <iostream>
using namespace std;

// TODO 1: 写一个函数模板 Max，参数是数组和长度，返回最大值
// 提示：template <typename T>
//       T Max(T arr[], int len) { ... }

// TODO 2: 写一个类模板 Box，属性是私有 T value
// 包含：构造函数、set(设置值)、get(返回值)
// 提示：template <class T>   （class 和 typename 在这里等价）
//       class Box { ... };

template <typename T>
T Max(T arr[], int len) {
  T max = arr[0];
  for (int i = 1; i < len; ++i) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }

  return max;
}

template <class T>
class Box {
 private:
  T value;

 public:
  Box(T v) : value(v) {}
  void set(T v) { value = v; }
  T get() { return value; }
};

int main() {
  // 测试函数模板
  int iarr[] = {1, 5, 3, 2, 4};
  double darr[] = {1.1, 2.2, 3.3, 2.0};
  char carr[] = {'a', 'c', 'b'};

  cout << Max(iarr, 5) << endl;
  cout << Max(darr, 4) << endl;
  cout << Max(carr, 3) << endl;

  // 测试类模板
  Box<int> ibox(100);
  Box<double> dbox(3.14);
  cout << ibox.get() << endl;
  cout << dbox.get() << endl;

  return 0;
}
