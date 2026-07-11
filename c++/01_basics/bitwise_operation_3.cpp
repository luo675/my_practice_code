#include <iostream>

using namespace std;

int main() {
  int a = 6, b = 4;
  cout << a << " " << b << endl;
  a = a ^ b;
  b = b ^ a;
  a = a ^ b;
  cout << a << " " << b << endl;

  return 0;
}