#include <iomanip>
#include <iostream>

using namespace std;

//-----类定义------

double pi = 3.14;

class Point {
 public:
  double x;
  double y;
  void setpoint();
};

class Circle {
 private:
  double cen_x;
  double cen_y;
  double r;

 public:
  void setcenter();
  void setradius();
  void getarea();
  void getlength();
  void judgecontain(Point po);
};
//----类实现------

void Point::setpoint() { cin >> x >> y; }

void Circle::setcenter() { cin >> cen_x >> cen_y; }

void Circle::setradius() { cin >> r; }

void Circle::getarea() {
  double area = pi * r * r;
  cout << fixed << setprecision(2) << area;
}

void Circle::getlength() {
  double length;
  length = 2 * pi * r;
  cout << fixed << setprecision(2) << length;
}

void Circle::judgecontain(Point po) {
  double dis2;
  dis2 = (cen_x - po.x) * (cen_x - po.x) + (cen_y - po.y) * (cen_y - po.y);
  if (dis2 <= r * r)
    cout << "yes";
  else
    cout << "no";
}

//-----主函数-----

int main() {
  Point po;
  Circle cir;
  cir.setcenter();
  cir.setradius();
  po.setpoint();
  cir.getarea();
  cout << " ";
  cir.getlength();
  cout << endl;
  cir.judgecontain(po);
  cout << endl;

  return 0;
}