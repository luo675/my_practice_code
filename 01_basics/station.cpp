#include <iostream>

using namespace std;

int main() {
  int a, n, m;
  long long x;
  std::cin >> a >> n >> m >> x;
  int up_a[n + 1], up_u[n + 1];
  int sum_a[n + 1], sum_u[n + 1];
  up_a[1] = 1, up_u[1] = 0;
  sum_a[1] = 1, sum_u[1] = 0;
  up_a[2] = 0, up_u[2] = 1;
  sum_a[2] = 1, sum_u[2] = 0;
  for (int i = 3; i <= n; i++) {
    up_a[i] = up_a[i - 1] + up_a[i - 2];
    up_u[i] = up_u[i - 1] + up_u[i - 2];
    sum_a[i] = sum_a[i - 1] + up_a[i] - up_a[i - 1];
    sum_u[i] = sum_u[i - 1] + up_u[i] - up_u[i - 1];
  }
  int u;
  if (sum_u[n - 1] != 0) {
    u = (m - sum_a[n - 1] * a) / sum_u[n - 1];
  } else {
    u = 0;
  }
  int x_num = sum_u[x] * u + sum_a[x] * a;
  std::cout << x_num << std::endl;

  return 0;
}