#include <iostream>
#include <string>

using namespace std;

class CClock {
 private:
  int h;
  int m;
  int s;

 public:
  CClock(int h, int m, int s) : h(h), m(m), s(s) {}
  CClock() : h(0), m(0), s(0) {}
  friend ostream& operator<<(ostream& os, const CClock& obj) {
    os << obj.h << " " << obj.m << " " << obj.s;
    return os;
  }
  int get1() { return h; }
  int get2() { return m; }
  int get3() { return s; }
};

class CRmb {
 private:
  int y;
  int j;
  int f;

 public:
  CRmb() : y(0), j(0), f(0) {}
  CRmb(int y, int j, int f) : y(y), j(j), f(f) {}
  friend ostream& operator<<(ostream& os, const CRmb& obj) {
    os << obj.y << " " << obj.j << " " << obj.f;
    return os;
  }
  int get1() { return y; }
  int get2() { return j; }
  int get3() { return f; }
};

template <typename T>

T add(T t1, T t2, int n) {
  int a[3], b[3], c[3];

  a[0] = t1.get1();
  b[0] = t1.get2();
  c[0] = t1.get3();

  a[1] = t2.get1();
  b[1] = t2.get2();
  c[1] = t2.get3();

  c[2] = c[0] + c[1];
  b[2] = c[2] / n;
  c[2] %= n;

  b[2] += b[0] + b[1];
  a[2] = b[2] / n;
  b[2] %= n;

  a[2] += a[0] + a[1];

  T t3(a[2], b[2], c[2]);

  return t3;
}

int main() {
  int h[2], m[2], s[2];
  cin >> h[0] >> m[0] >> s[0];
  cin >> h[1] >> m[1] >> s[1];
  CClock c1(h[0], m[0], s[0]), c2(h[1], m[1], s[1]), c3;
  c3 = add<CClock>(c1, c2, 60);
  cout << c3 << endl;

  int y[2], j[2], f[2];
  cin >> y[0] >> j[0] >> f[0];
  cin >> y[1] >> j[1] >> f[1];
  CRmb r1(y[0], j[0], f[0]), r2(y[1], j[1], f[1]), r3;
  r3 = add<CRmb>(r1, r2, 10);
  cout << r3 << endl;

  return 0;
}