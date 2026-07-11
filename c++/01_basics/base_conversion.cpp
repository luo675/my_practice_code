// 全靠的ai

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 将余数转换为对应的字符（0-9, A-J）
char getChar(int n) {
  if (n <= 9) return n + '0';
  return n - 10 + 'A';
}

int main() {
  int n, r;
  if (!(cin >> n >> r)) return 0;

  cout << n << "=";  // 先输出左半部分

  string res = "";
  int tempN = n;

  if (tempN == 0) {
    res = "0";
  } else {
    while (tempN != 0) {
      int rem = tempN % r;
      tempN /= r;

      // 核心逻辑：修正负余数
      if (rem < 0) {
        rem -= r;
        tempN += 1;
      }
      res += getChar(rem);
    }
  }

  // 因为是从低位算到高位，所以要反转字符串
  reverse(res.begin(), res.end());

  cout << res << "(base" << r << ")" << endl;

  return 0;
}