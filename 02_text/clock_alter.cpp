#include <iostream>

using namespace std;

class CClock {
 private:
  int h, m, s;

 public:
  CClock(int h, int m, int s) : h(h), m(m), s(s) {}
  CClock() { h = 0, m = 0, s = 0; }
  ~CClock() {}
  void disp() { cout << h << ":" << m << ":" << s << endl; }

  void check() {
    if (s >= 60) {
      m++;
      s = 0;
    }

    if (m > 59) {
      h++;
      m = 0;
    }

    if (h > 11) {
      h = 0;
    }

    if (s < 0) {
      s = 59;
      m--;
    }

    if (m < 0) {
      m = 59;
      h--;
    }

    if (h < 0) {
      h = 11;
    }
  }

  CClock operator++() {
    ++s;
    check();
    return *this;
  }

  CClock operator--(int) {
    CClock temp(*this);
    --s;
    check();
    return temp;
  }
};

int main() {
  int h, m, s, t;
  cin >> h >> m >> s >> t;

  CClock c(h, m, s);

  while (t--) {
    int x;
    cin >> x;
    if (x > 0) {
      while (x--) {
        ++c;
      }
    } else {
      while (x < 0) {
        c--;
        x++;
      }
    }

    c.disp();
  }

  return 0;
}