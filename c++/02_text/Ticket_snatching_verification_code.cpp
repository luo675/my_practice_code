#include <iostream>

using namespace std;

template <typename T>
bool judge(T* t) {
  for (int i = 0; i < 6; ++i) {
    for (int j = i + 1; j < 6; ++j) {
      if (t[i] > t[j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int t;
  if (!(cin >> t)) return 0;

  while (t--) {
    char c;
    cin >> c;

    if (c == 'c') {
      char* p = new char[6];
      for (int i = 0; i < 6; ++i) {
        cin >> p[i];
      }

      if (judge(p)) {
        cout << "Valid" << endl;
      } else {
        cout << "Invalid" << endl;
      }
      delete[] p;

    } else if (c == 'i') {
      int* p = new int[6];
      for (int i = 0; i < 6; ++i) {
        cin >> p[i];
      }

      if (judge(p)) {
        cout << "Valid" << endl;
      } else {
        cout << "Invalid" << endl;
      }
      delete[] p;

    } else if (c == 'f') {
      float* p = new float[6];
      for (int i = 0; i < 6; ++i) {
        cin >> p[i];
      }

      if (judge(p)) {
        cout << "Valid" << endl;
      } else {
        cout << "Invalid" << endl;
      }
      delete[] p;
    }
  }

  return 0;
}