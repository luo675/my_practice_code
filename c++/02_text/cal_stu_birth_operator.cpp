#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isLeap(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && isLeap(year)) return 29;
  return days[month - 1];
}

int daysFromEpoch(int year, int month, int day) {
  int total = 0;

  total += (year - 1) * 365;

  total += (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

  for (int m = 1; m < month; ++m) {
    total += daysInMonth(year, m);
  }

  total += day;
  return total;
}

class Student {
 private:
  string name;
  int year, month, day;

 public:
  Student() {}
  Student(string n, int y, int m, int d) : name(n), year(y), month(m), day(d) {}
  void set(const string& n, int y, int m, int d) {
    name = n;
    year = y;
    month = m;
    day = d;
  }
  string getName() const { return name; }
  int operator-(const Student& other) const {
    int d1 = daysFromEpoch(year, month, day);
    int d2 = daysFromEpoch(other.year, other.month, other.day);
    int d = d1 - d2;
    if (d < 0) {
      d = -d;
    }
    return d;
  }
};

int main() {
  int n;
  cin >> n;
  Student* stu = new Student[n];

  string name;
  int y, m, d;
  for (int i = 0; i < n; ++i) {
    cin >> name >> y >> m >> d;
    stu[i].set(name, y, m, d);
  }

  int maxDiff = -1;
  int idx1 = -1, idx2 = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int diff = stu[i] - stu[j];
      if (diff > maxDiff) {
        maxDiff = diff;
        idx1 = i;
        idx2 = j;
      }
    }
  }

  if (idx1 != -1 && idx2 != -1) {
    cout << stu[idx1].getName() << "和" << stu[idx2].getName()
         << "年龄相差最大，为" << maxDiff << "天。" << endl;
  }
  delete[] stu;
  return 0;
}