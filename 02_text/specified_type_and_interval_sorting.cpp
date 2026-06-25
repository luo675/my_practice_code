#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void sorting(T* t, int n, int be, int en) {
  for (int i = be; i < en; i++) {
    for (int j = i + 1; j < en; j++) {
      if (t[i] > t[j]) {
        T temp = t[i];
        t[i] = t[j];
        t[j] = temp;
      }
    }
  }
}

template <typename T>
void disp(T t[], int n) {
  cout << "[";
  for (int i = 0; i < n; ++i) {
    cout << t[i];
    if (i != n - 1) cout << ", ";
  }
  cout << "]" << endl;
}

template <>
void disp<float>(float t[], int n) {
  cout << "[";
  for (int i = 0; i < n; ++i) {
    cout << fixed << setprecision(1) << t[i];
    if (i != n - 1) cout << ", ";
  }
  cout << "]" << endl;
}

int main() {
  int t;
  if (!(cin >> t)) return 0;

  while (t--) {
    int n;
    string s;
    cin >> s >> n;

    if (s == "int") {
      int* p = new int[n];
      int q[2];
      char c[4];
      cin >> c[0] >> q[0] >> c[1] >> q[1] >> c[2] >> c[3];
      for (int i = 0; i < n; ++i) {
        cin >> p[i];
      }

      if (q[0] > q[1]) {
        disp(p, n);
        continue;
      }
      if (q[0] < 0) {
        q[0] = 0;
      }
      if (q[1] > n) {
        q[1] = n;
      }

      sorting(p, n, q[0], q[1]);
      disp(p, n);

      delete[] p;
    } else if (s == "string") {
      string* p = new string[n];
      int q[2];
      char c[4];
      cin >> c[0] >> q[0] >> c[1] >> q[1] >> c[2] >> c[3];
      for (int i = 0; i < n; ++i) {
        cin >> p[i];
      }

      if (q[0] > q[1]) {
        disp(p, n);
        continue;
      }
      if (q[0] < 0) {
        q[0] = 0;
      }
      if (q[1] > n) {
        q[1] = n;
      }

      sorting(p, n, q[0], q[1]);
      disp(p, n);

      delete[] p;
    } else if (s == "float") {
      float* p = new float[n];
      int q[2];
      char c[4];
      cin >> c[0] >> q[0] >> c[1] >> q[1] >> c[2] >> c[3];
      for (int i = 0; i < n; ++i) {
        cin >> p[i];
      }

      if (q[0] > q[1]) {
        disp(p, n);
        continue;
      }
      if (q[0] < 0) {
        q[0] = 0;
      }
      if (q[1] > n) {
        q[1] = n;
      }

      sorting(p, n, q[0], q[1]);
      disp(p, n);

      delete[] p;
    }
  }

  return 0;
}