#include <iostream>
#include <string>

using namespace std;

class Birth {
 private:
  int y;
  int m;
  int d;

 public:
  Birth() {}
  Birth(int y, int m, int d) : y(y), m(m), d(d) {}
  ~Birth() {}
  void output() {
    cout << y << ".";
    if (m < 10) cout << "0";
    cout << m << ".";
    if (d < 10) cout << "0";
    cout << d << endl;
  }

  int y2() { return y / 100; }
};

class IDcard {
 private:
  int type;
  string idnum;
  Birth date;

 public:
  IDcard(int t, string num, Birth bir) : type(t), idnum(num), date(bir) {}

  ~IDcard() {};

  IDcard(const IDcard& other) {
    type = other.type;
    idnum = other.idnum;
    date = other.date;
    type = 2;
    if (idnum.size() == 15) {
      add();
    }
  }

  void add() {
    int a = date.y2();
    idnum.insert(6, to_string(a));
    int sum = 0;
    for (char c : idnum) {
      sum += c - '0';
    }
    sum = sum % 10;
    if (sum == 0) {
      idnum.push_back('X');
    } else
      idnum.push_back('0' + sum);
  }

  void output() {
    cout << "type=2 birth=";
    date.output();
    cout << "ID=" << idnum << endl;
  }
};

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    int t;
    string num;
    int y, m, d;
    cin >> t >> num >> y >> m >> d;
    Birth b1(y, m, d);
    IDcard id1(t, num, b1);
    IDcard id2 = id1;
    id2.output();
  }

  return 0;
}