#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int** arr = new int*[n];
    for (int i = 0; i < n; ++i) {
      arr[i] = new int[n];
    }

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    while (num <= n * n) {
      // 先向右，再向下，然后向左，最后向上
      for (int i = left; i <= right; ++i) {
        arr[top][i] = num;
        ++num;
      }
      ++top;
      for (int i = top; i <= bottom; ++i) {
        arr[i][right] = num;
        ++num;
      }
      --right;
      for (int i = right; i >= left; --i) {
        arr[bottom][i] = num;
        ++num;
      }
      --bottom;
      for (int i = bottom; i >= top; --i) {
        arr[i][left] = num;
        ++num;
      }
      ++left;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << arr[i][j];
        if (j != n - 1) cout << " ";
      }
      cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) delete[] arr[i];
    delete[] arr;
  }

  return 0;
}