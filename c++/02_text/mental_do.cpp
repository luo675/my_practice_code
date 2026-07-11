#include <iostream>
#include <string>

using namespace std;

class mental {
 private:
  int hard;
  int weight;
  int volumn;

 public:
  mental() {}
  mental(int h, int w, int v) : hard(h), weight(w), volumn(v) {}
  void disp() {
    cout << "硬度" << hard << "--重量" << weight << "--体积" << volumn << endl;
  }
  friend mental operator+(const mental& m1, const mental& m2) {
    mental result;
    result.hard = m2.hard + m1.hard;
    result.volumn = m2.volumn + m1.volumn;
    result.weight = m2.weight + m1.weight;

    return result;
  }

  friend mental operator*(const mental& m1, int n) {
    mental result;
    result.volumn = m1.volumn * n;
    result.hard = m1.hard;
    result.weight = m1.weight;

    return result;
  }

  mental& operator++() {
    hard++;
    volumn = volumn * 1.1;
    weight = weight * 1.1;
    return *this;
  }

  mental operator--(int) {
    mental temp = *this;
    hard--;
    volumn = volumn * 0.9;
    weight = weight * 0.9;
    return temp;
  }
};

int main() {
  int h[2], w[2], v[2];
  cin >> h[0] >> w[0] >> v[0];
  cin >> h[1] >> w[1] >> v[1];
  mental m1(h[0], w[0], v[0]), m2(h[1], w[1], v[1]);

  mental m3, m4;

  m3 = m1 + m2;

  int n;
  cin >> n;
  m4 = m1 * n;

  ++m1;

  m2--;

  m3.disp();
  m4.disp();
  m1.disp();
  m2.disp();

  return 0;
}