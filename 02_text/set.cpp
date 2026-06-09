#include <iostream>
using namespace std;

class CSet {
 private:
  int n;
  int* data;

 public:
  CSet() : n(0), data(nullptr) {}

  CSet(int num) : n(num), data(nullptr) {
    if (n > 0) {
      data = new int[n];
      for (int i = 0; i < n; ++i) {
        cin >> data[i];
      }
    }
  }

  CSet(const CSet& other) : n(other.n), data(nullptr) {
    if (n > 0) {
      data = new int[n];
      for (int i = 0; i < n; ++i) {
        data[i] = other.data[i];
      }
    }
  }

  ~CSet() { delete[] data; }

  CSet& operator=(const CSet& other) {
    if (this != &other) {
      delete[] data;
      n = other.n;
      data = nullptr;
      if (n > 0) {
        data = new int[n];
        for (int i = 0; i < n; ++i) {
          data[i] = other.data[i];
        }
      }
    }
    return *this;
  }

  bool contains(int x) const {
    for (int i = 0; i < n; ++i) {
      if (data[i] == x) return true;
    }
    return false;
  }

  CSet operator+(const CSet& other) const {
    int newSize = n;
    for (int i = 0; i < other.n; ++i) {
      if (!contains(other.data[i])) ++newSize;
    }

    CSet res;
    res.n = newSize;
    if (newSize > 0) {
      res.data = new int[newSize];

      for (int i = 0; i < n; ++i) res.data[i] = data[i];

      int idx = n;
      for (int i = 0; i < other.n; ++i) {
        if (!contains(other.data[i])) {
          res.data[idx++] = other.data[i];
        }
      }
    }
    return res;
  }

  CSet operator*(const CSet& other) const {
    CSet res;

    int newSize = 0;
    for (int i = 0; i < n; ++i) {
      if (other.contains(data[i])) ++newSize;
    }
    res.n = newSize;
    if (newSize > 0) {
      res.data = new int[newSize];
      int idx = 0;
      for (int i = 0; i < n; ++i) {
        if (other.contains(data[i])) {
          res.data[idx++] = data[i];
        }
      }
    }
    return res;
  }

  CSet operator-(const CSet& other) const {
    CSet res;
    int newSize = 0;
    for (int i = 0; i < n; ++i) {
      if (!other.contains(data[i])) ++newSize;
    }
    res.n = newSize;
    if (newSize > 0) {
      res.data = new int[newSize];
      int idx = 0;
      for (int i = 0; i < n; ++i) {
        if (!other.contains(data[i])) {
          res.data[idx++] = data[i];
        }
      }
    }
    return res;
  }

  void disself() const {
    for (int i = 0; i < n; ++i) {
      cout << data[i];
      if (i != n - 1) cout << " ";
    }
  }

  friend ostream& operator<<(ostream& os, const CSet& s) {
    s.disself();
    return os;
  }

  void disp(const CSet& obj) const {
    cout << "A:" << *this << endl;
    cout << "B:" << obj << endl;
    cout << "A+B:" << (*this + obj) << endl;
    cout << "A*B:" << (*this * obj) << endl;
    cout << "(A-B)+(B-A):" << ((*this - obj) + (obj - *this)) << endl;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a;
    CSet s1(a);
    cin >> b;
    CSet s2(b);
    s1.disp(s2);
    if (t != 0) cout << endl;
  }
  return 0;
}