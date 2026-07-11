#include <iostream>

using namespace std;

class Group {
 protected:
 public:
  virtual int add(int x, int y) = 0;
  virtual int sub(int x, int y) = 0;
};

class GroupA : public Group {
 private:
 public:
  int add(int x, int y) override { return x + y; }
  int sub(int x, int y) override { return x - y; }
};

class GroupB : public Group {
 public:
  int add(int x, int y) override { return x + y; }
  int sub(int x, int y) override {
    int a[3], b[3], c[3], d;
    a[0] = x / 100;
    a[1] = (x - a[0] * 100) / 10;
    a[2] = (x - a[0] * 100 - a[1] * 10);
    b[0] = y / 100;
    b[1] = (y - b[0] * 100) / 10;
    b[2] = (y - b[0] * 100 - b[1] * 10);
    for (int i = 0; i < 3; ++i) {
      c[i] = a[i] - b[i];
      if (c[i] < 0) c[i] = 10 + c[i];
    }
    d = c[0] * 100 + c[1] * 10 + c[2];
    return d;
  }
};

class GroupC : public Group {
 public:
  int add(int x, int y) override {
    int a[3], b[3], c[3], d;
    a[0] = x / 100;
    a[1] = (x - a[0] * 100) / 10;
    a[2] = (x - a[0] * 100 - a[1] * 10);
    b[0] = y / 100;
    b[1] = (y - b[0] * 100) / 10;
    b[2] = (y - b[0] * 100 - b[1] * 10);
    for (int i = 0; i < 3; ++i) {
      c[i] = a[i] + b[i];
      if (c[i] > 10) c[i] = c[i] - 10;
    }
    d = c[0] * 100 + c[1] * 10 + c[2];
    return d;
  }
  int sub(int x, int y) override {
    int a[3], b[3], c[3], d;
    a[0] = x / 100;
    a[1] = (x - a[0] * 100) / 10;
    a[2] = (x - a[0] * 100 - a[1] * 10);
    b[0] = y / 100;
    b[1] = (y - b[0] * 100) / 10;
    b[2] = (y - b[0] * 100 - b[1] * 10);
    for (int i = 0; i < 3; ++i) {
      c[i] = a[i] - b[i];
      if (c[i] < 0) c[i] = 10 + c[i];
    }
    d = c[0] * 100 + c[1] * 10 + c[2];
    return d;
  }
};

int main() {
  int t;
  if (!(cin >> t)) return 0;

  while (t--) {
    Group* p1;
    int type;
    cin >> type;
    if (type == 1)
      p1 = new GroupA;
    else if (type == 2)
      p1 = new GroupB;
    else
      p1 = new GroupC;

    int x, y;
    char ch;
    cin >> x >> ch >> y;
    if (ch == '+')
      cout << p1->add(x, y) << endl;

    else
      cout << p1->sub(x, y) << endl;

    delete p1;
  }

  return 0;
}