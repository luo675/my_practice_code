#include <iostream>

using namespace std;

int solve() {
  int n, m;
  cin >> n >> m;
  if (m < 0 || n < 0) {
    return 0;
  }
  if (m == n) {
    cout << 1 << endl;
    return 0;
  }

  long long ans = 1;
  for (int i = 1; i <= m; i++) {
    ans = ans * (n - i + 1) / i;
  }
  cout << ans << endl;
  return 0;
}

int main() {
  int times;
  cin >> times;
  while (times--) {
    int a = solve();
  }

  return 0;
}