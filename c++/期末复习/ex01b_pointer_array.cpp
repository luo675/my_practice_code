/*
 * 练习1b：指针数组 vs 数组指针
 *
 * 补全代码，输出：
 * 10 20 30               ← 指针数组遍历
 * 1 2 3 4 5              ← 数组指针遍历
 */
#include <iostream>
using namespace std;

int main() {
  int a = 10, b = 20, c = 30;

  // TODO 1: 声明一个指针数组 ptr_arr，存放 a, b, c 的地址
  // 然后用循环输出 *ptr_arr[i]
  int* p[3];
  p[0] = &a;
  p[1] = &b;
  p[2] = &c;
  for (int i = 0; i < 3; ++i) {
    cout << *p[i] << " ";
  }
  cout << endl;

  int arr2d[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
  int (*p2)[5] = arr2d;
  for (int i = 0; i < 5; ++i) {
    cout << (*p2)[i] << " ";
  }
  // TODO 2: 声明一个数组指针 p，指向 arr2d 的第一行
  // 然后用循环输出 p[i]
  // 提示：int (*p)[5] = arr2d;
  // arr2d 退化为指向第一行的指针，类型正好是 int(*)[5]

  return 0;
}
