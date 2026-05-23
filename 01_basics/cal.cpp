#include <iostream>

using namespace std;

int main() {
  float D, d;
  cin >> D >> d;
  float f;
  f = (D * D - d * d) / (4 * D);
  cout << f;

  return 0;
}