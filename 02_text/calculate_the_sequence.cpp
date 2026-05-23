#include <iostream>

using namespace std;

int main() {
  int n;
  if (!(cin >> n)) {
    return 0;
  }

  int f[1001] = {0};

  for (int x = 1; x <= n; ++x) {
    f[x] = 1;
    for (int i = 1; i <= x / 2; ++i) {
      f[x] += f[i];
    }
  }
  cout << f[n] << endl;
  return 0;
}