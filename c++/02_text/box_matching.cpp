#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a[3], b[3];
    for (int i = 0; i < 3; ++i) cin >> a[i];
    for (int i = 0; i < 3; ++i) cin >> b[i];
    int temp = a[0];
    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        if (a[i] > a[j]) {
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
        }
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        if (b[i] > b[j]) {
          temp = b[i];
          b[i] = b[j];
          b[j] = temp;
        }
      }
    }
    int c = 0, d = 0;
    for (int i = 0; i < 3; i++) {
      if (a[i] < b[i])
        ++c;
      else if (a[i] > b[i])
        ++d;
      else
        ++c, ++d;
    }
    if (c == 3 || d == 3)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }

  return 0;
}