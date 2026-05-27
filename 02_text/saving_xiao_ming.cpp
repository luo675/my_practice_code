#include <iostream>
#include <string>

using namespace std;

class Date {
 protected:
  int year;
  int month;
  int day;

 public:
  Date() {}
  Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

class Time {
 protected:
  int hour;
  int minute;
  int second;

 public:
  Time() {}
  Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
};

class Work : public Date, public Time {
 protected:
  int id;

 public:
  Work() {}
  Work(int i, int y, int m, int d, int h, int mi, int s)
      : id(i), Date(y, m, d), Time(h, mi, s) {}
  friend bool before(const Work& w1, const Work& w2);
  void display() {
    cout << "The urgent Work is No." << id << ": ";

    cout << year << "/";

    if (month < 10) {
      cout << "0";
    }
    cout << month << "/";

    if (day < 10) {
      cout << "0";
    }
    cout << day << " ";

    if (hour < 10) {
      cout << "0";
    }
    cout << hour << ":";

    if (minute < 10) {
      cout << "0";
    }
    cout << minute << ":";

    if (second < 10) {
      cout << "0";
    }
    cout << second;
  }
};

bool before(const Work& w1, const Work& w2) {  // false就是选后者
  if (w1.year > w2.year) {
    return false;
  } else if (w1.year == w2.year) {
    if (w1.month > w2.month) {
      return false;
    } else if (w1.month == w2.month) {
      if (w1.day > w2.day) {
        return false;
      } else if (w1.day == w2.day) {
        if (w1.day > w2.day) {
          return false;
        } else if (w1.hour == w2.hour) {
          if (w1.minute > w2.minute) {
            return false;
          } else if (w1.minute == w2.minute) {
            if (w1.second > w2.second) {
              return false;
            }
          }
        }
      }
    }
  }

  return true;
}

int main() {
  int i1, i2, y1, y2, m1, m2, d1, d2, h1, h2, mi1, mi2, s1, s2;
  cin >> i1 >> y1 >> m1 >> d1 >> h1 >> mi1 >> s1;
  cin >> i2;
  Work w1(i1, y1, m1, d1, h1, mi1, s1);
  while (i2 != 0) {
    cin >> y2 >> m2 >> d2 >> h2 >> mi2 >> s2;
    Work w2(i2, y2, m2, d2, h2, mi2, s2);
    if (!before(w1, w2)) {
      w1 = w2;
    }
    cin >> i2;
  }
  w1.display();

  return 0;
}