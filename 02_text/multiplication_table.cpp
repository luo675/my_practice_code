#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 9; ++i) {
    if (i * n < 10)
      cout << " " << i << "* " << n << "= " << i * n << endl;
    else
      cout << " " << i << "* " << n << "=" << i * n << endl;
  }

  return 0;
}