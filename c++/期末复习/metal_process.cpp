#include <iostream>
#include <string>

using namespace std;

class Metal {
 private:
  int hard;
  int heave;
  int volume;

 public:
  Metal() : hard(0), heave(0), volume(0) {}
  Metal(int h, int he, int v) : hard(h), heave(he), volume(v) {}
  void disp() {
    cout << "硬度" << hard << "--重量" << heave << "--体积" << volume << endl;
  }
  friend Metal operator+(const Metal m1, const Metal m2) {
    Metal m3;
    m3.hard = m1.hard + m2.hard;
    m3.heave = m1.heave + m2.heave;
    m3.volume = m1.volume + m2.volume;

    return m3;
  }
  friend Metal operator*(const Metal m1, int n) {
    Metal m2;
    m2.hard = m1.hard;
    m2.heave = m1.heave;
    m2.volume = m1.volume * n;

    return m2;
  }

  Metal& operator++() {
    hard++;
    heave *= 1.1;
    volume *= 1.1;

    return *this;
  }

  Metal operator--(int) {
    Metal old = *this;
    hard--;
    heave *= 0.9;
    volume *= 0.9;

    return old;
  }
};

int main() {
  int h[2], he[2], v[2];
  cin >> h[0] >> he[0] >> v[0];
  cin >> h[1] >> he[1] >> v[1];
  Metal m1(h[0], he[0], v[0]), m2(h[1], he[1], v[1]);
  Metal m3, m4;

  m3 = m1 + m2;
  m3.disp();

  int n;
  cin >> n;
  m4 = m1 * n;
  m4.disp();

  ++m1;
  m1.disp();

  m2--;
  m2.disp();

  return 0;
}