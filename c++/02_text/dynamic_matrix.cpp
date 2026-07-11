#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    int** arr = new int*[m];
    for (int i = 0; i < m; ++i) arr[i] = new int[n];

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> arr[i][j];
      }
    }

    int max = arr[0][0], min = arr[0][0];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (arr[i][j] > max) max = arr[i][j];
        if (arr[i][j] < min) min = arr[i][j];
      }
    }

    cout << min << " " << max << endl;

    for (int i = 0; i < m; ++i) delete[] arr[i];
    delete[] arr;
  }

  return 0;
}