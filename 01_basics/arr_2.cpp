#include <iostream>

using namespace std;

int main() {
  int arr[3][4][5];
  int i = 0;

  for (auto& row_2d : arr) {
    int j = 0;
    for (auto& row_1d : row_2d) {
      int k = 0;
      for (auto& val : row_1d) {
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