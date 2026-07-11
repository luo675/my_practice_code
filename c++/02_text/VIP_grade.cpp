#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Member {
 protected:
  int code;
  string name;
  int grade;

 public:
  Member() {}
  Member(int c, string n, int g) : code(c), name(n), grade(g) {}
  ~Member() {}
  virtual void disp() {
    cout << "普通会员" << code << "--" << name << "--" << grade << endl;
  }
  virtual void add(int m) { grade += m; }
  virtual void exc(int m) {
    int n = m / 100;
    grade -= n * 100;
  }
};

class VIP : public Member {
 private:
  int addr;
  int exr;

 public:
  VIP() {}
  VIP(int c, string n, int g, int a, int e)
      : Member(c, n, g), addr(a), exr(e) {}
  ~VIP() {}
  void disp() override {
    cout << "贵宾会员" << code << "--" << name << "--" << grade << endl;
  }
  void add(int m) override { grade += addr * m; }
  void exc(int m) override {
    int n = m / exr;
    grade -= n * exr;
  }
};

int main() {
  Member* pm;
  int c, g;
  string n;
  cin >> c >> n >> g;
  Member mm(c, n, g);
  pm = &mm;
  int m1, m2;
  cin >> m1 >> m2;
  pm->add(m1);
  pm->exc(m2);
  pm->disp();

  int ar, er;
  cin >> c >> n >> g >> ar >> er;
  VIP vv(c, n, g, ar, er);
  pm = &vv;
  cin >> m1 >> m2;
  pm->add(m1);
  pm->exc(m2);
  pm->disp();

  return 0;
}