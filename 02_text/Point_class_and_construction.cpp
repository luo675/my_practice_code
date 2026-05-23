#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

class Point {
  double x, y;

 public:
  Point();
  Point(double x_value, double y_value);
  double getx();
  double gety();
  void setx(double x_value);
  void sety(double y_value);
  double distancetoanotherpoint(Point p);
};

Point::Point() {
  x = 0.0;
  y = 0.0;
}

Point::Point(double x_value, double y_value) {
  x = x_value;
  y = y_value;
}

void Point::setx(double x_value) { x = x_value; }

void Point::sety(double y_value) { y = y_value; }

double getx() {
  double x;
  cin >> x;
  return x;
}

double gety() {
  double y;
  cin >> y;
  return y;
}

double Point::distancetoanotherpoint(Point p) {
  double dis2 = (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
  double dis = sqrt(dis2);
  cout << "Distance of Point(";
  cout << fixed << setprecision(2) << x;
  cout << ",";
  cout << fixed << setprecision(2) << y;
  cout << ") to Point(";
  cout << fixed << setprecision(2) << p.x;
  cout << ",";
  cout << fixed << setprecision(2) << p.y;
  cout << ") is ";

  return dis;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    Point p1, p2;
    p1.setx(getx());
    p1.sety(gety());
    p2.setx(getx());
    p2.sety(gety());
    double dis = p1.distancetoanotherpoint(p2);
    cout << fixed << setprecision(2) << dis << endl;
  }

  return 0;
}
