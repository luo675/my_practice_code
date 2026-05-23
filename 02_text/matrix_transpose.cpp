#include <iostream>

using namespace std;

void bian(int arr[3][3]) {
  int arr_new[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) arr_new[i][j] = arr[j][i];
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << arr_new[i][j];
      cout << " ";
    }
    cout << endl;
  }
}

int main() {
  int arr[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) cin >> arr[i][j];
  }
  bian(arr);

  return 0;
}