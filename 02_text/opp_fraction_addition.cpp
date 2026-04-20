#include <iostream>

using namespace std;

int GCD(int a, int b);

class Fract {
 public:
  int fenzi[2];
  int fenmu[2];

  void add(int zi[2], int mu[2]) {
    int c[2];
    int d[2];
    d[1] = mu[0] * mu[1];
    c[0] = zi[0] * mu[1], c[1] = zi[1] * mu[0];
    d[0] = c[0] + c[1];
    int e = GCD(d[0], d[1]);
    cout << d[0] / e << "/" << d[1] / e << endl;
  }
};

int main() {
  int n;
  if (!(cin >> n)) return 0;
  while (n--) {
    Fract fra;
    cin >> fra.fenzi[0] >> fra.fenmu[0] >> fra.fenzi[1] >> fra.fenmu[1];
    fra.add(fra.fenzi, fra.fenmu);
  }

  return 0;
}

int GCD(int a, int b) {
  if (a < b) {
    int temp = a;
    a = b;
    b = temp;
  }
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}
