#include <iostream>
using namespace std;

int main() {
  int arr[3][4][5];

  // 使用范围 for 进行初始化
  int i = 0;
  for (auto& row_2d : arr) {  // 必须是引用！row_2d 是 int[4][5]
    int j = 0;
    for (auto& row_1d : row_2d) {  // 必须是引用！row_1d 是 int[5]
      int k = 0;
      for (auto& val : row_1d) {  // val 是具体元素的引用
        val = i + j + k;
        cout << val << " ";
        k++;
      }
      cout << endl;
      j++;
    }
    i++;
  }
  return 0;
}