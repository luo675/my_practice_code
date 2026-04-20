#include <iostream>

using namespace std;

class Data {
 private:
  int year;
  int month;
  int day;

 public:
  Data();
  Data(int y, int m, int d);
  int getYear();
  int getMonth();
  int getDay();
  void setDate(int y, int m, int d);
  void print();
  void addOneDay();

  bool isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
  }

  int daysInMonth(int y, int m) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m];
  }
};

Data::Data() {
  year = 1900;
  month = 1;
  day = 1;
}

Data::Data(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
}

int Data::getYear() { return year; }
int Data::getMonth() { return month; }
int Data::getDay() { return day; }

void Data::setDate(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
}

void Data::print() {
  cout << year << "/";
  if (month < 10) cout << "0";
  cout << month << "/";
  if (day < 10) cout << "0";
  cout << day << endl;
}

void Data::addOneDay() {
  day++;
  if (day > daysInMonth(year, month)) {
    day = 1;
    month++;
    if (month > 12) {
      month = 1;
      year++;
    }
  }
}

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    int y, m, d;
    cin >> y >> m >> d;
    Data dt(y, m, d);
    cout << "Today is ";
    dt.print();
    dt.addOneDay();
    cout << "Tomorrow is ";
    dt.print();
  }
  return 0;
}