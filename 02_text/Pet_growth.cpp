#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class CDate {
 private:
  int year;
  int month;
  int day;

 public:
  CDate(int y, int m, int d) : year(y), month(m), day(d) {}
  bool compare_date(CDate d1) {
    if (year < d1.year) return true;
    if (year == d1.year && month < d1.month) return true;
    if (year == d1.year && month == d1.month && day < d1.day) return true;
    return false;
  }

  bool isLeap(int y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
  int cal(CDate d1) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    long long total1 = 0;
    for (int y = 1; y < year; y++) {  
      total1 += isLeap(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
      total1 += daysInMonth[m];
      if (m == 2 && isLeap(year)) total1++;
    }
    total1 += day;

    long long total2 = 0;
    for (int y = 1; y < d1.year; y++) {
      total2 += isLeap(y) ? 366 : 365;
    }
    for (int m = 1; m < d1.month; m++) {
      total2 += daysInMonth[m];
      if (m == 2 && isLeap(d1.year)) total2++;
    }
    total2 += d1.day;

    return static_cast<int>(total2 - total1);
  }
};

class Pet {
 protected:
  string name;
  float length;
  float weight;
  CDate current;
  int total_day;

 public:
  Pet(string n, float l, float w, CDate c)
      : name(n), length(l), weight(w), current(c) {}
  virtual void display(CDate day) = 0;
  void calculate_day(CDate date1) { total_day = current.cal(date1); }
};

class Cat : public Pet {
 public:
  Cat(string n, float l, float w, CDate c) : Pet(n, l, w, c) {}
  void add() {
    length += total_day * 0.1f;
    weight += total_day * 0.2f;
  }
  void display(CDate day) {
    add();
    cout << name << " after " << total_day << " day: length=";
    cout << fixed << setprecision(2) << length;
    cout << ",weight=" << fixed << setprecision(2) << weight << endl;
  }
};

class Dog : public Pet {
 public:
  Dog(string n, float l, float w, CDate c) : Pet(n, l, w, c) {}
  void add() {
    length += total_day * 0.2f;
    weight += total_day * 0.1f;
  }
  void display(CDate day) {
    add();
    cout << name << " after " << total_day << " day: length=";
    cout << fixed << setprecision(2) << length;
    cout << ",weight=" << fixed << setprecision(2) << weight << endl;
  }
};

int main() {
  int t;
  if (!(cin >> t)) return 0;

  int y1, m1, d1;
  cin >> y1 >> m1 >> d1;
  CDate startDate(y1, m1, d1); 

  while (t--) {
    int k;
    cin >> k;
    string n;
    float l, w;
    int y2, m2, d2;
    cin >> n >> l >> w >> y2 >> m2 >> d2;
    CDate targetDate(y2, m2, d2);  
    if (targetDate.compare_date(startDate)) {
      cout << "error" << endl;
      continue; 
    }

    Pet* pt;
    if (k == 1) {
      pt = new Cat(n, l, w, startDate);  
    } else {
      pt = new Dog(n, l, w, startDate);
    }
    pt->calculate_day(targetDate);  
    pt->display(targetDate);

    delete pt;
  }

  return 0;
}