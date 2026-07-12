#include <iostream>
#include <string>

using namespace std;

class appliance {
 protected:
  int id;
  int w;

 public:
  appliance() : id(0), w(0) {}
  appliance(int i, int w) : w(w), id(i) {}
  virtual void disp() = 0;
};

class fan : virtual public appliance {
 protected:
  int xiang;
  int li;

 public:
  fan(int i, int w, int x, int l) : appliance(i, w), xiang(x), li(l) {}
  void setx(int n) { xiang = n; }
  void setl(int n) { li = n; }
};

class addwater : virtual public appliance {
 protected:
  float now;
  float max;

 public:
  addwater(int i, int w, int n, int m) : appliance(i, w), now(n), max(m) {}
  int warn() {
    if (now >= max * 0.5) {
      return 1;
    } else if (now < max * 0.5 && now >= max * 0.1) {
      return 2;
    } else {
      return 3;
    }
  }
};

class waterfan : public fan, public addwater {
 private:
  int rate;

 public:
  waterfan(int i, int w, int x, int l, int n, int m, int r)
      : appliance(i, w), fan(i, w, x, l), addwater(i, w, n, m), rate(r) {}
  void disp() override {
    cout << "加湿风扇--挡位" << rate << endl;
    cout << "编号" << id << "--功率" << w << "W" << endl;
    if (xiang == 0) {
      cout << "定向吹风--风力" << li << "级" << endl;
    } else {
      cout << "旋转吹风--风力" << li << "级" << endl;
    }
    cout << "实际水容量" << now << "升--水量";
    int a = warn();
    if (a == 1) {
      cout << "正常";
    } else if (a == 2) {
      cout << "偏低";
    } else {
      cout << "不足";
    }
    cout << endl;
  }
  void change(int r) {
    rate = r;
    if (r == 0) {
    } else if (r == 1) {
      xiang = 0;
      li = 1;
    } else if (r == 2) {
      xiang = 1;
      li = 2;
    } else if (r == 3) {
      xiang = 1;
      li = 3;
    }
  }
};

int main() {
  int t;
  cin >> t;

  while (t--) {
    int i, w, x, l, n, m, r;
    cin >> i >> w >> x >> l >> n >> m >> r;
    waterfan w1(i, w, x, l, n, m, r);
    cin >> r;
    w1.change(r);
    w1.disp();
  }
  return 0;
}