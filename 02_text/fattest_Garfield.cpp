#include <iostream>
#include <string>

using namespace std;

class cat {
 private:
  string name;
  int weight;

 public:
  cat() {}

  cat(string na, int we) : name(na), weight(we) {}

  ~cat() {}

  void getname(string na) { name = na; }

  void getweight(int we) { weight = we; }

  void output() { cout << name; }

  int comw() { return weight; }
};

int main() {
  int n;
  if (!(cin >> n)) return 0;

  cat* c = new cat[n];
  for (int i = 0; i < n; ++i) {
    string n;
    int w;
    cin >> n >> w;
    c[i].getname(n);
    c[i].getweight(w);
  }

  cat temp("aaa", 111);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (c[i].comw() > c[j].comw()) {
        temp = c[i];
        c[i] = c[j];
        c[j] = temp;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    c[i].output();
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << endl;

  return 0;
}