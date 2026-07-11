#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  const char* p[] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
  while (t--) {
    int m;
    cin >> m;
    if (m <= 0 || m >= 13)
      cout << "error" << endl;
    else
      cout << p[m - 1] << endl;
  }

  return 0;
}