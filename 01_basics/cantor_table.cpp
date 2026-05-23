#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  int index = 1;
  while (1) {
    sum += index;
    if (sum >= n) break;
    index++;
  }
  int x = n - sum + index;
  if (index % 2 == 0)  // 偶数
    cout << x << "/" << index + 1 - x << endl;
  else  // 奇数
    cout << index + 1 - x << "/" << x << endl;

  return 0;
}