/*
 * 练习1：指针运算 + 常量指针 vs 指针常量
 *
 * 补全以下代码，让程序输出：
 * 20 30 40 50 60
 * const int* 不能修改指向的值
 * int* const 不能修改指针指向
 */
#include <iostream>
using namespace std;

int main() {
  int arr[5] = {10, 20, 30, 40, 50};

  // TODO 1: 用指针 p 遍历 arr，让每个元素 +10 后输出
  // 提示：用 int* p = arr; 然后通过指针遍历
  int* p = arr;
  for (int i = 0; i < 5; ++i) {
    p[i] += 10;
    cout << p[i] << " ";
  }
  cout << endl;
  // 你的代码写在这里（for循环遍历，*p += 10 或是 p[i] += 10）
  // 输出格式：每个数后面一个空格，最后 endl

  // TODO 2: 声明一个 const int* 类型的指针 cp
  // 往下写一行：const int* cp = arr;
  // 再写一行：*cp = 100;   ← 这行应该报错，观察报错信息
  const int* cp = arr;
  *cp = 100;

  // TODO 3: 声明一个 int* const 类型的指针 cp2 指向 arr
  // 往下写一行：int* const cp2 = arr;
  // 再写一行：cp2 = nullptr;  ← 这行应该报错，观察报错信息
  int* const cp2 = arr;
  cp2 = nullptr;

  cout << "--- 练习完成 ---" << endl;
  return 0;
}
