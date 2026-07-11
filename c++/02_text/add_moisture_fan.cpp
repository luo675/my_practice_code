#include <iostream>
#include <string>
using namespace std;

class Appliance {
 protected:
  int id;
  int power;

 public:
  Appliance(int i = 0, int p = 0) : id(i), power(p) {}
  virtual void print() const {
    cout << "编号" << id << "--功率" << power << "W" << endl;
  }
  virtual ~Appliance() {}
};

class Fan : virtual public Appliance {
 protected:
  int windDirection;
  int windPower;

 public:
  Fan(int i = 0, int p = 0, int wd = 0, int wp = 0)
      : Appliance(i, p), windDirection(wd), windPower(wp) {}
  void setWindDirection(int d) { windDirection = d; }
  void setWindPower(int p) { windPower = p; }
  virtual void print() const override {
    Appliance::print();
    cout << (windDirection == 0 ? "定向吹风" : "旋转吹风") << "--风力"
         << windPower << "级" << endl;
  }
};

class Humidifier : virtual public Appliance {
 protected:
  double actualWater;
  double maxWater;

 public:
  Humidifier(int i = 0, int p = 0, double aw = 0, double mw = 0)
      : Appliance(i, p), actualWater(aw), maxWater(mw) {}
  int warning() const {
    double ratio = actualWater / maxWater;
    if (ratio >= 0.5)
      return 1;
    else if (ratio >= 0.1)
      return 2;
    else
      return 3;
  }
  virtual void print() const override {
    Appliance::print();
    cout << "实际水容量" << actualWater << "升--";
    int w = warning();
    if (w == 1)
      cout << "水量正常";
    else if (w == 2)
      cout << "水量偏低";
    else
      cout << "水量不足";
    cout << endl;
  }
};

class HumidFan : public Fan, public Humidifier {
 protected:
  int gear;

 public:
  HumidFan(int i = 0, int p = 0, int wd = 0, int wp = 0, double aw = 0,
           double mw = 0, int g = 0)
      : Appliance(i, p), Fan(i, p, wd, wp), Humidifier(i, p, aw, mw), gear(g) {}

  void adjustGear(int g) {
    gear = g;
    switch (g) {
      case 1:
        setWindDirection(0);
        setWindPower(1);
        break;
      case 2:
        setWindDirection(1);
        setWindPower(2);
        break;
      case 3:
        setWindDirection(1);
        setWindPower(3);
        break;
      default:
        break;
    }
  }

  virtual void print() const override {
    cout << "加湿风扇--档位" << gear << endl;
    cout << "编号" << id << "--功率" << power << "W" << endl;
    cout << (windDirection == 0 ? "定向吹风" : "旋转吹风") << "--风力"
         << windPower << "级" << endl;
    cout << "实际水容量" << actualWater << "升--";
    int w = warning();
    if (w == 1)
      cout << "水量正常";
    else if (w == 2)
      cout << "水量偏低";
    else
      cout << "水量不足";
    cout << endl;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int id, power, windDirection, windPower, gear;
    double actualWater, maxWater;
    cin >> id >> power >> windDirection >> windPower >> actualWater >>
        maxWater >> gear;
    HumidFan hf(id, power, windDirection, windPower, actualWater, maxWater,
                gear);
    int newGear;
    cin >> newGear;
    hf.adjustGear(newGear);
    hf.print();
  }
  return 0;
}