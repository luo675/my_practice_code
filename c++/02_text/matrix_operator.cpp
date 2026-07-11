#include <iostream>

using namespace std;

class matrix {
 private:
  int ma[100][100] = {0};
  int m = 0, n = 0;

 public:
  matrix() {}
  matrix(int m, int n) : m(m), n(n) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> ma[i][j];
      }
    }
  }

  matrix operator+(const matrix& obj) {
    matrix result;
    result.m = m;
    result.n = n;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result.ma[i][j] = ma[i][j] + obj.ma[i][j];
      }
    }

    return result;
  }

  matrix operator-(const matrix& obj) {
    matrix result;
    result.m = m;
    result.n = n;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result.ma[i][j] = ma[i][j] - obj.ma[i][j];
      }
    }

    return result;
  }

  void disp() {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << ma[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    int m, n;
    cin >> m >> n;
    matrix m1(m, n);
    matrix m2(m, n);
    matrix m3, m4;
    m3 = m1 + m2;
    m4 = m1 - m2;
    cout << "Add:" << endl;
    ;
    m3.disp();
    cout << "Minus:" << endl;
    m4.disp();
    cout << "-----------------" << endl;
    ;
  }

  return 0;
}