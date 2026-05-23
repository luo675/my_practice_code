#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int times;
  cin >> times;
  while (times--) {
    double a, b, c;
    cin >> a >> b;
    c = 0.6 * a + 0.4 * b;
    cout << fixed << setprecision(1) << c << endl;
  }

  return 0;
}