#include <iostream>
using namespace std;

class polygon {
 protected:
  int number;

 private:
  int side_length[100];

 public:
  polygon() : number(0) {}

  polygon(int n, int sides[]) : number(n) {
    for (int i = 0; i < n && i < 100; i++) {
      side_length[i] = sides[i];
    }
  }

  virtual int perimeter() {
    int sum = 0;
    for (int i = 0; i < number; i++) {
      sum += side_length[i];
    }
    return sum;
  }

  void display() { cout << number << " " << perimeter() << endl; }
};

class rectangle : public polygon {
 private:
  int height;
  int width;

 public:
  rectangle() : height(0), width(0) { number = 4; }

  rectangle(int h, int w) : height(h), width(w) { number = 4; }

  int perimeter() override { return 2 * (height + width); }

  void display() { cout << number << " " << perimeter() << endl; }
};

class equal_polygon : public polygon {
 private:
  int side_len;

 public:
  equal_polygon() : side_len(0) { number = 0; }

  equal_polygon(int n, int s) : side_len(s) { number = n; }

  int perimeter() override { return number * side_len; }

  void display() { cout << number << " " << perimeter() << endl; }
};

int main() {
  int n;
  if (!(cin >> n)) return 0;

  while (n--) {
    int type;
    cin >> type;

    if (type == 0) {
      int sides[100];
      int cnt = 0;
      int val;
      while (cin >> val && val != -1) {
        sides[cnt++] = val;
      }
      polygon p(cnt, sides);
      p.display();
    } else if (type == 1) {
      int h, w;
      cin >> h >> w;
      rectangle r(h, w);
      r.display();
    } else if (type == 2) {
      int num, side;
      cin >> num >> side;
      equal_polygon ep(num, side);
      ep.display();
    }
  }

  return 0;
}