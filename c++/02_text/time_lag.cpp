#include <iostream>

using namespace std;

class Time {
 private:
  int h;
  int m;
  int s;

 public:
  Time(int h1, int m1, int s1) : h(h1), m(m1), s(s1) {}
  ~Time() {}
  friend long cal(Time t1, Time t2);
  void output() { cout << h << "时" << m << "分" << s << "秒"; }
};

long cal(Time t1, Time t2) {
  long x = 0;
  long a, b;
  a = t1.h * 3600 + t1.m * 60 + t1.s;
  b = t2.h * 3600 + t2.m * 60 + t2.s;
  x = b - a;
  if (x < 0) x = -x;

  return x;
}

int main() {
  int t;
  if (!(cin >> t)) return 0;

  while (t--) {
    int h1, h2, m1, m2, s1, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    Time t1(h1, m1, s1), t2(h2, m2, s2);
    long x = cal(t1, t2);
    t1.output();
    cout << "--";
    t2.output();
    cout << "时间差为";
    cout << x << "秒" << endl;
  }
}