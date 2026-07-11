#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class box {
 private:
  string num;
  int length;
  int width;
  int height;

 public:
  box() : length(0), width(0), height(0) {}
  box(string id, int l, int w, int h) : num(id), height(h) {
    if (l < w) swap(l, w);
    length = l;
    width = w;
  }

  void set(string id, int l, int w, int h) {
    num = id;
    if (l < w) swap(l, w);
    length = l;
    width = w;
    height = h;
  }

  int volume() const { return length * width * height; }

  string getNum() const { return num; }

  bool judge(const box& obj) const {
    if (length >= obj.length && width >= obj.width && height >= obj.height)
      return true;
    else
      return false;
  }

  int operator-(const box& obj) const {
    if (judge(obj)) {
      return obj.volume();
    }
    return 0;
  }

  void disp(const box& innerBox, int maxOver) const {
    cout << num << "盒子放入" << innerBox.getNum() << "盒子溢出的水最多，为"
         << maxOver << "。" << endl;
  }
};

int main() {
  int n;
  if (!(cin >> n) || n <= 0) return 0;

  box* b = new box[n];
  for (int i = 0; i < n; ++i) {
    string id;
    int l, w, h;
    cin >> id >> l >> w >> h;
    b[i].set(id, l, w, h);
  }

  int maxOver = 0;
  int A = -1, B = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        int overflow = b[i] - b[j];  // b[j]放入b[i]
        if (overflow > maxOver) {
          maxOver = overflow;
          A = i;  // 外盒
          B = j;  // 内盒
        }
      }
    }
  }

  if (A != -1) {
    b[B].disp(b[A], maxOver);
  }

  delete[] b;
  return 0;
}