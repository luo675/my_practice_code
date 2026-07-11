#include <iostream>

using namespace std;

class CMatrix {
 private:
  int m, n;
  int** data;

 public:
  CMatrix(int m, int n) : m(m), n(n) {
    data = new int*[m];
    for (int i = 0; i < m; i++) {
      data[i] = new int[n];
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> data[i][j];
      }
    }
  }
  CMatrix() : m(0), n(0), data(nullptr) {}

  CMatrix operator+(const CMatrix& obj) const {
    CMatrix res;
    res.m = m;
    res.n = n;
    res.data = new int*[m];
    for (int i = 0; i < m; ++i) {
      res.data[i] = new int[n];
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        res.data[i][j] = data[i][j] + obj.data[i][j];
      }
    }

    return res;
  }

  void dis() {
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

  CMatrix(const CMatrix& other) : m(other.m), n(other.n) {
    data = new int*[m];
    for (int i = 0; i < m; ++i) {
      data[i] = new int[n];
      for (int j = 0; j < n; ++j) data[i][j] = other.data[i][j];
    }
  }

  CMatrix& operator=(const CMatrix& other) {
    if (this == &other) return *this;

    int** newData = new int*[other.m];
    for (int i = 0; i < other.m; ++i) {
      newData[i] = new int[other.n];
      for (int j = 0; j < other.n; ++j) newData[i][j] = other.data[i][j];
    }

    for (int i = 0; i < m; ++i) delete[] data[i];
    delete[] data;

    m = other.m;
    n = other.n;
    data = newData;
    return *this;
  }

  ~CMatrix() {
    for (int i = 0; i < m; ++i) delete[] data[i];
    delete[] data;
  }
};

int main() {
  int t;
  cin >> t;

  while (t--) {
    int m, n;
    cin >> m >> n;
    CMatrix m1(m, n);
    CMatrix m2(m, n);
    CMatrix m3;

    m3 = m1 + m2;

    m3.dis();
  }

  return 0;
}