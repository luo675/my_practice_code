#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

class Equation {
 private:
  double a, b, c;

 public:
  Equation(double _a = 1.0, double _b = 1.0, double _c = 0.0)
      : a(_a), b(_b), c(_c) {}

  void set(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
  }

  void getRoot() {
    double delta = b * b - 4 * a * c;

    cout << fixed << setprecision(2);

    if (delta > 0) {
      double x1 = (-b + sqrt(delta)) / (2 * a);
      double x2 = (-b - sqrt(delta)) / (2 * a);
      cout << "x1=" << x1 << " x2=" << x2 << endl;
    } else if (abs(delta) < 1e-9) {
      double x = -b / (2 * a);
      cout << "x1=x2=" << x << endl;
    } else {
      double realPart = -b / (2 * a);
      double imagPart = sqrt(-delta) / (2 * a);
      cout << "x1=" << realPart << "+" << imagPart << "i "
           << "x2=" << realPart << "-" << imagPart << "i" << endl;
    }
  }
};

int main() {
  int t;
  if (!(cin >> t)) return 0;

  Equation eq;
  while (t--) {
    double a, b, c;
    cin >> a >> b >> c;
    eq.set(a, b, c);
    eq.getRoot();
  }

  return 0;
}