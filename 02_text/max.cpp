#include <iostream>

using namespace std;

int main() {
  double a, b, c;
  cin >> a >> b >> c;
  if (b > c) c = b;
  if (a > c) c = a;
  cout << c << endl;

  return 0;
}