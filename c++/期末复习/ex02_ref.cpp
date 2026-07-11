/*
 * 练习2：引用传递 vs 值传递
 *
 * 补全以下代码，观察输出结果
 * 预期输出：
 * before: a=3 b=5
 * after value_swap: a=3 b=5   （值传递不改变原值）
 * after ref_swap:  a=5 b=3   （引用传递改变原值）
 */
#include <iostream>
using namespace std;

// TODO 1: 写一个值传递的 swap 函数（参数用 int）
void value_swap(int x, int y) {
  // 在这里交换 x 和 y
  int temp = x;
  x = y;
  y = temp;
}

// TODO 2: 写一个引用传递的 swap 函数（参数用 int&）
void ref_swap(int& x, int& y) {
  // 在这里交换 x 和 y
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int a = 3, b = 5;
  cout << "before: a=" << a << " b=" << b << endl;
  // TODO 3: 调用 value_swap(a, b) 然后输出
  value_swap(a, b);
  cout << "after value_swap: a=" << a << " b=" << b << endl;

  // TODO 4: 调用 ref_swap(a, b) 然后输出
  ref_swap(a, b);
  cout << "after ref_swap:  a=" << a << " b=" << b << endl;

  return 0;
}
