#include <iostream>
#include <string>

using namespace std;

class CVehicle {
 protected:
  int max_speed, speed, weight;

 public:
  CVehicle(int m, int s, int w) : max_speed(m), speed(s), weight(w) {}
  void virtual display() {
    cout << "Vehicle:" << endl;
    cout << "max_speed:" << max_speed << endl;
    cout << "speed:" << speed << endl;
    cout << "weight:" << weight << endl;
    cout << endl;
  }
};

class CBicycle : virtual public CVehicle {
 protected:
  int h;

 public:
  CBicycle(int m, int s, int w, int h) : CVehicle(m, s, w), h(h) {}
  void virtual display() {
    cout << "Bicycle:" << endl;
    cout << "max_speed:" << max_speed << endl;
    cout << "speed:" << speed << endl;
    cout << "weight:" << weight << endl;
    cout << "height:" << h << endl;
    cout << endl;
  }
};

class CMotocar : virtual public CVehicle {
 protected:
  int set;

 public:
  CMotocar(int m, int s, int w, int se) : CVehicle(m, s, w), set(se) {}
  void virtual display() {
    cout << "Motocar:" << endl;
    cout << "max_speed:" << max_speed << endl;
    cout << "speed:" << speed << endl;
    cout << "weight:" << weight << endl;
    cout << "seat_num:" << set << endl;
    cout << endl;
  }
};

class CMotocycle : public CBicycle, public CMotocar {
 protected:
 public:
  CMotocycle(int m, int s, int w, int h, int se)
      : CVehicle(m, s, w), CBicycle(m, s, w, h), CMotocar(m, s, w, se) {}
  void display() {
    cout << "Motocycle:" << endl;
    cout << "max_speed:" << max_speed << endl;
    cout << "speed:" << speed << endl;
    cout << "weight:" << weight << endl;
    cout << "height:" << h << endl;
    cout << "seat_num:" << set << endl;
  }
};

int main() {
  int max, v, w, h, set;
  cin >> max >> v >> w >> h >> set;
  CVehicle V1(max, v, w);
  V1.display();
  CBicycle V2(max, v, w, h);
  V2.display();
  CMotocar V3(max, v, w, set);
  V3.display();
  CMotocycle V4(max, v, w, h, set);
  V4.display();

  return 0;
}