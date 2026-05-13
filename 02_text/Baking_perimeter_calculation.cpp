#include <iostream>
using namespace std;

class polygon {
 protected:
  int number;
  int c;
  int side_length[100];

 public:
  polygon() : number(0), c(0) {}

  void set_sides() {
    int len, i = 0;
    while (cin >> len && len != -1) {
      side_length[i] = len;
      i++;
    }
    number = i;
  }

  virtual int perimeter() {
    c = 0;
    for (int i = 0; i < number; ++i) {
      c += side_length[i];
    }
    return c;
  }

  virtual void display() { cout << number << " " << c << endl; }

  virtual ~polygon() {}
};

class rectangle : public polygon {
 protected:
  int height;
  int width;

 public:
  rectangle() {
    number = 4;
    cin >> height >> width;
  }

  int perimeter() override {
    c = 2 * (height + width);
    return c;
  }

  void display() override { cout << 4 << " " << c << endl; }
};

class equal_polygon : public polygon {
 protected:
  int side_len;

 public:
  equal_polygon() { cin >> number >> side_len; }

  int perimeter() override {
    c = number * side_len;
    return c;
  }

  void display() override { cout << number << " " << c << endl; }
};

int main() {
  int n;
  if (!(cin >> n)) return 0;

  while (n--) {
    int type;
    cin >> type;
    polygon* p = nullptr;

    if (type == 0) {
      p = new polygon();
      p->set_sides();
    } else if (type == 1) {
      p = new rectangle();
    } else if (type == 2) {
      p = new equal_polygon();
    }

    p->perimeter();
    p->display();
    delete p;
  }

  return 0;
}