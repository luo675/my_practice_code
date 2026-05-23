#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const double EPS = 1e-3;

class CTriangle {
 private:
  double a, b, c;
  string type;

  bool isEqual(double x, double y) { return fabs(x - y) < EPS; }

 public:
  CTriangle(double side1, double side2, double side3) {
    a = side1;
    b = side2;
    c = side3;
    determineType();
  }

  ~CTriangle() {
    a = b = c = 0;
    type = "none";
  }

  void determineType() {
    if (a + b <= c + EPS || a + c <= b + EPS || b + c <= a + EPS) {
      type = "no triangle";
      return;
    }

    double s[3] = {a, b, c};
    sort(s, s + 3);
    double s1 = s[0], s2 = s[1], s3 = s[2];

    bool isRight = isEqual(s1 * s1 + s2 * s2, s3 * s3);
    bool isEquilateral = isEqual(s1, s2) && isEqual(s2, s3);
    bool isIsosceles = isEqual(s1, s2) || isEqual(s2, s3) || isEqual(s1, s3);

    if (isEquilateral) {
      type = "equilateral triangle";
    } else if (isIsosceles && isRight) {
      type = "isosceles right triangle";
    } else if (isIsosceles) {
      type = "isosceles triangle";
    } else if (isRight) {
      type = "right triangle";
    } else {
      type = "general triangle";
    }
  }

  double calculateArea() {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }

  void print() {
    if (type == "no triangle") {
      cout << type << endl;
    } else {
      cout << type << ", " << fixed << setprecision(1) << calculateArea()
           << endl;
    }
  }
};

int main() {
  int n;
  if (!(cin >> n)) return 0;

  while (n--) {
    double s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    CTriangle tri(s1, s2, s3);
    tri.print();
  }

  return 0;
}