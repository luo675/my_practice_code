#include <iostream>

using namespace std;

int main() {
  unsigned int n;
  cin >> n;
  do {
    if ((n & (n - 1)) == 0)
      cout << "yes!!!" << endl;
    else
      cout << "No" << endl;
  } while (cin >> n);
  return 0;
}