#include <iostream>
#include <string>

using namespace std;

class CDate {
 private:
  int year, month, day;

 public:
  CDate() {}
  CDate(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
  }
  bool isLeapYear() {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  }
  int getYear() { return year; }
  int getMonth() { return month; }
  int getDay() { return day; }
  int getDayofYear()  // 计算日期从当年1月1日算起的天数
  {
    int i, sum = day;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear())
      for (i = 0; i < month; i++) sum += b[i];
    else
      for (i = 0; i < month; i++) sum += a[i];

    return sum;
  }

  bool unlimited() {
    if (year == 0 && month == 0 && day == 0) {
      return true;
    } else
      return false;
  }

  bool expired() {
    if (year < 2015) {
      return true;
    } else if (year == 2015 && month < 4) {
      return true;
    } else if (month == 4 && day < 7) {
      return true;
    } else
      return false;
  }

  int cal() {
    int days;
    days = getDayofYear();                   // 当年时间
    for (int i = year - 1; i > 2015; i--) {  // 2016年及以后的整年
      CDate d1(i, 12, 31);
      days += d1.getDayofYear();
    }
    if (year > 2015) {  // 大于2015就要加上2015剩余的天数
      CDate d2(2015, 12, 31);
      CDate d3(2015, 4, 7);
      days += d2.getDayofYear();
      days -= d3.getDayofYear();
    } else {
      CDate d3(2015, 4, 7);
      days -= d3.getDayofYear();
    }
    return days;
  }
};

class software {
 private:
  string name;
  string type;
  CDate d;
  string media;

 public:
  software(string na, string ty, string me, CDate d1)
      : name(na), type(ty), media(me), d(d1) {}
  ~software() {}
  software(const software& other) {
    name = other.name;
    type = "B";
    media = "H";
    d = other.d;
  }
  void output() {
    cout << "name:" << name << endl;

    cout << "type:";
    if (type == "O") {
      cout << "original" << endl;
    } else if (type == "B") {
      cout << "backup" << endl;
    } else {
      cout << "trial" << endl;
    }

    cout << "media:";
    if (media == "D") {
      cout << "optical disk" << endl;
    } else if (media == "U") {
      cout << "USB disk" << endl;
    } else {
      cout << "hard disk" << endl;
    }

    cout << "this software ";
    if (d.unlimited()) {
      cout << "has unlimited use" << endl;
    } else if (d.expired()) {
      cout << "has expired" << endl;
    } else {
      int day = d.cal();
      cout << "is going to be expired in " << day << " days" << endl;
    }

    cout << endl;
  }
};

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    string na;
    string ty;
    string me;
    int y, m, d;
    cin >> na >> ty >> me >> y >> m >> d;
    CDate d1(y, m, d);
    software s1(na, ty, me, d1);
    s1.output();
    software s2 = s1;
    s2.output();
  }

  return 0;
}