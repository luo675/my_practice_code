#include <iostream>
using namespace std;

template <typename T>
class Matrix {
 private:
  int rows, cols;
  T** data;

  void allocate(int m, int n) {
    rows = m;
    cols = n;
    data = new T*[m];
    for (int i = 0; i < m; ++i) {
      data[i] = new T[n];
    }
  }

  void deallocate() {
    if (data) {
      for (int i = 0; i < rows; ++i) {
        delete[] data[i];
      }
      delete[] data;
      data = nullptr;
    }
  }

 public:
  Matrix(int m, int n) : data(nullptr) { allocate(m, n); }

  ~Matrix() { deallocate(); }

  Matrix(const Matrix& other) : data(nullptr) {
    allocate(other.rows, other.cols);
    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j) data[i][j] = other.data[i][j];
  }

  void input() {
    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j) cin >> data[i][j];
  }

  void transport() {
    T** newData = new T*[cols];
    for (int j = 0; j < cols; ++j) {
      newData[j] = new T[rows];
    }
    for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j) newData[j][i] = data[i][j];
    deallocate();
    data = newData;
    swap(rows, cols);
  }

  void print() const {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (j > 0) cout << " ";
        cout << data[i][j];
      }
      cout << "\n";
    }
  }
};

int main() {
  int t;
  if (!(cin >> t)) return 0;

  while (t--) {
    char c;
    int m, n;
    cin >> c >> m >> n;

    if (c == 'I') {
      Matrix<int> mat(m, n);
      mat.input();
      mat.transport();
      mat.print();
    } else if (c == 'D') {
      Matrix<double> mat(m, n);
      mat.input();
      mat.transport();
      mat.print();
    } else if (c == 'C') {
      Matrix<char> mat(m, n);
      mat.input();
      mat.transport();
      mat.print();
    }
  }

  return 0;
}