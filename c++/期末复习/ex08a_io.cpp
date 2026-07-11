/*
 * 练习8a：I/O 流格式控制
 *
 * 补全代码，用格式控制让程序输出：
 * |  123|
 * |123  |
 * 3.14
 * 3.1416
 */
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int n = 123;
  double pi = 3.1415926;
  cout << "|" << setw(5) << right << n << "|" << endl;
  // TODO 1: 用 setw(5) 右对齐输出 n
  // 输出格式：|  123|
  cout << "|" << setw(5) << left << n << "|" << endl;
  // TODO 2: 用 setw(5) 左对齐输出 n
  // 输出格式：|123  |
  cout << setprecision(3) << pi << endl;
  // TODO 3: 用 setprecision(3) 输出 pi（保留3位有效数字）
  cout << fixed << setprecision(4) << pi << endl;
  // TODO 4: 用 fixed + setprecision(4) 输出 pi（保留4位小数）

  return 0;
}
