/*
 * 练习5b：运算符重载 - << >> 和 []
 *
 * 补全代码，让程序能够：
 * 1. 用 cin >> arr 输入3个数
 * 2. 用 cout << arr 输出这3个数
 * 3. 用 arr[1] 访问第2个元素
 *
 * 输入样例：
 * 10 20 30
 *
 * 预期输出：
 * 输入: [10, 20, 30]
 * arr[1] = 20
 */
#include <iostream>
using namespace std;

class IntArray {
  int data[3];  // 固定大小，不用 new，不需要深拷贝
 public:
  IntArray() { data[0] = data[1] = data[2] = 0; }

  // TODO 1: 重载 >> （友元函数，从输入流读取3个int）
  // 声明：friend istream& operator>>(istream& in, IntArray& arr);
  friend istream& operator>>(istream& in, IntArray& arr) {
    in >> arr.data[0] >> arr.data[1] >> arr.data[2];
    return in;
  }
  // TODO 2: 重载 << （友元函数，输出格式 [a, b, c]）
  // 声明：friend ostream& operator<<(ostream& out, const IntArray& arr);
  friend ostream& operator<<(ostream& out, const IntArray& arr) {
    out << "[" << arr.data[0] << "," << arr.data[1] << "," << arr.data[2]
        << "]";
    return out;
  }
  // TODO 3: 重载 [] （成员函数，返回 data[i] 的引用）
  // 这样外面才能对 arr[i] 赋值
  int& operator[](int i) { return data[i]; }
};

int main() {
  IntArray arr;

  cout << "输入3个数: ";
  cin >> arr;

  cout << "输出: " << arr << endl;
  cout << "arr[1] = " << arr[1] << endl;

  return 0;
}
