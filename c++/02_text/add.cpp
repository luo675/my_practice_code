#include <iostream>
#include <string>
using namespace std;

class Four {
 private:
  int value;

  static int tofour(const string& s) {
    int res = 0;
    for (char c : s) {
      res = res * 4 + (c - '0');
    }
    return res;
  }

  static string toten(int v) {
    if (v == 0) return "0";
    string res;
    while (v > 0) {
      res = char('0' + v % 4) + res;
      v /= 4;
    }
    return res;
  }

 public:
  Four() : value(0) {}
  Four(const string& s) : value(tofour(s)) {}
  Four(int v) : value(v) {}

  Four operator+(const Four& other) const { return Four(value + other.value); }

  void print() const { cout << toten(value) << endl; }
};

int main() {
  int n;
  cin >> n;

  Four sum;
  string num;

  while (n--) {
    cin >> num;
    Four f(num);
    sum = sum + f;
  }

  sum.print();

  return 0;
}