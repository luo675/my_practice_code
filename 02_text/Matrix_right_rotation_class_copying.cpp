#include <iostream>

using namespace std;

class matrix {
 private:
  int m;
  int n;
  int** data;

 public:
  matrix(int m, int n) : m(m), n(n) {
    data = new int*[m];
    for (int i = 0; i < m; ++i) {
      data[i] = new int[n];
    }
  }
  matrix(const matrix& other) {
    m = other.m;
    n = other.n;

    data = new int*[m];
    for (int i = 0; i < m; ++i) {
      data[i] = new int[n];
    }
  }
  void input() {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> data[i][j];
      }
    }
  }

  void output() {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << data[i][j];
        if (j != n - 1) {
          cout << " ";
        }
      }
      cout << endl;
    }
  }

  void rotation(const matrix& other) {
    for (int i = 0; i < other.m; ++i) {
      for (int j = 0; j < other.n; ++j) {
        data[j][other.m - i - 1] = other.data[i][j];
      }
    }
  }

  ~matrix() {
    for (int i = 0; i < m; ++i) {
      delete[] data[i];
    }
    delete[] data;
  }
};

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    int m, n;
    cin >> m >> n;
    matrix m1(m, n);
    m1.input();
    matrix m2(n, m);
    cout << "before:" << endl;
    m1.output();
    m2.rotation(m1);
    cout << "after:" << endl;
    m2.output();

    cout << endl;
  }

  return 0;
}