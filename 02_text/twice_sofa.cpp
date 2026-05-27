#include <iostream>
#include <string>

using namespace std;

class Furniture {
 protected:
  int m;

 public:
  Furniture() { m = 0; }
};

class Bed : virtual public Furniture {
 public:
  Bed() {}
  void Sleep() { cout << "Sleeping..." << endl; }
};

class Sofa : virtual public Furniture {
 public:
  Sofa() {}
  void WatchTV() { cout << "Watching TV." << endl; }
};

class SleepSofa : public Bed, public Sofa {
 public:
  SleepSofa() {}
  void FoldOut() { cout << "Fold out the sofa." << endl; }
};

int main() {
  string type;
  while (cin >> type) {
    if (type == "Bed") {
      Bed b;
      b.Sleep();
    } else if (type == "Sofa") {
      Sofa s;
      s.WatchTV();

    } else {
      SleepSofa s;
      s.FoldOut();
    }
  }

  return 0;
}