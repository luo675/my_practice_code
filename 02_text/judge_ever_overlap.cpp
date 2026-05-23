#include <iostream>

using namespace std;

int _max(int a, int b) {
  if (a < b)
    return b;
  else
    return a;
}

int _min(int a, int b) {
  if (a < b) {
    return a;
  } else
    return b;
}

class rectangle {
 private:
  int x1, x2;
  int y1, y2;
  int left;
  int right;
  int top;
  int bottom;

 public:
  rectangle(int _x1, int _y1, int _x2, int _y2)
      : x1(_x1), x2(_x2), y1(_y1), y2(_y2) {
    left = _min(x1, x2);
    right = _max(x1, x2);
    top = _max(y1, y2);
    bottom = _min(y1, y2);
  }
  ~rectangle() {}
  friend bool judge(rectangle r1, rectangle r2);
};

bool judge(rectangle r1, rectangle r2) {
  return !(r1.right < r2.left || r2.right < r1.left || r1.top < r2.bottom ||
           r2.top < r1.bottom);
}



int main() {
  int t;
  if (!(cin >> t)) return 0;

  while (t--) {
    int a[8];
    for (int i = 0; i < 8; ++i) {
      cin >> a[i];
    }
    rectangle r1(a[0], a[1], a[2], a[3]);
    rectangle r2(a[4], a[5], a[6], a[7]);
    if (judge(r1, r2)) {
      cout << "overlapped" << endl;
    } else
      cout << "not overlapped" << endl;
  }

  return 0;
}