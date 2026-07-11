#include <iostream>
#include <string>

using namespace std;

template <typename T>
T Find(T t[], int n) {  // 返回的是得票最高的人的代号
  T* p = new T[n];      // p储存有几个候选人
  p[0] = t[0];
  int m = 1;  // m代表现在储存了几个候选人

  int count[n] = {0};  // 代表对应第几个第一次出现的人有几票
  count[0] = 1;

  for (int i = 1; i < n; ++i) {
    int x = 0;  // x判断这一回合j有没有遇到一样的
    for (int j = 0; j < m; ++j) {
      if (t[i] == p[j]) {
        count[j]++;
        x = 1;
      }
    }
    if (x == 0) {
      p[m] = t[i];
      count[m] = 1;
      m++;
    }
  }

  int index = 0;
  for (int i = 1; i < m; ++i) {
    if (count[i] > count[index]) {
      index = i;
    }
  }
  T ans = p[index];
  delete[] p;
  return ans;
}

int main() {
  int t;
  if (!(cin >> t)) return 0;

  while (t--) {
    char c;
    int n;
    cin >> c >> n;
    int count = 0;

    if (c == 'I') {
      int* p = new int[n];
      for (int i = 0; i < n; ++i) {
        cin >> p[i];
      }

      int res = Find<int>(p, n);
      for (int i = 0; i < n; ++i) {
        if (res == p[i]) {
          count++;
        }
      }

      cout << res << " " << count << endl;
      delete[] p;
    } else if (c == 'C') {
      char* p = new char[n];
      for (int i = 0; i < n; ++i) {
        cin >> p[i];
      }

      char res = Find<char>(p, n);
      for (int i = 0; i < n; ++i) {
        if (res == p[i]) {
          count++;
        }
      }

      cout << res << " " << count << endl;
      delete[] p;
    } else if (c == 'S') {
      string* p = new string[n];
      for (int i = 0; i < n; ++i) {
        cin >> p[i];
      }

      string res = Find<string>(p, n);
      for (int i = 0; i < n; ++i) {
        if (res == p[i]) {
          count++;
        }
      }

      cout << res << " " << count << endl;
      delete[] p;
    }
  }

  return 0;
}