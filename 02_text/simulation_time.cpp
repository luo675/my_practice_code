#include <cstring>
#include <iostream>
using namespace std;

class Time {
 protected:
  int h;
  int m;
  int s;

 public:
  Time(int h, int m, int s) : h(h), m(m), s(s) {}
};

class Time_12hours : public Time {
 protected:
  char interval[5];

 public:
  Time_12hours(char in[5], int h, int m, int s) : Time(h, m, s) {
    strncpy(interval, in, sizeof(interval) - 1);
  }

  void add() {
    ++s;
    if (s >= 60) {
      s = 0;
      m++;
    }
    if (m >= 60) {
      m = 0;
      h++;
    }
    if (h >= 12) {
      h = 0;
      change();
    }
  }

  void reduce() {
    --s;
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
      change();
    }
  }

  void change() {
    if (interval[0] == 'A') {
      interval[0] = 'P';
    } else {
      interval[0] = 'A';
    }
  }

  void print() {
    cout << interval << " ";
    if (h < 10) {
      cout << "0" << h << ":";
    } else {
      cout << h << ":";
    }

    if (m < 10) {
      cout << "0" << m << ":";
    } else {
      cout << m << ":";
    }

    if (s < 10) {
      cout << "0" << s << endl;
    } else {
      cout << s << endl;
    }
  }
};

int main() {
  int x;
  cin >> x;
  while (x != 0) {
    char in[5], type;
    int h, m, s, t;
    cin >> h >> m >> s >> type >> t;
    if (x == 121) {
      in[0] = 'A';
      in[1] = 'M';
      in[2] = '\0';
    } else {
      in[0] = 'P';
      in[1] = 'M';
      in[2] = '\0';
    }

    Time_12hours t1(in, h, m, s);

    if (type == '+') {
      for (int i = 0; i < t; ++i) {
        t1.add();
      }
    } else {
      for (int i = 0; i < t; ++i) {
        t1.reduce();
      }
    }

    t1.print();
    cin >> x;
  }
}