#include <iostream>

using namespace std;

void sort(int& a, int& b, int& c);

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    sort(a, b, c);
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}

void sort(int& a, int& b, int& c) {
  int temp;
  if (a < b) {
    temp = a;
    a = b;
    b = temp;
  }
  if (a < c) {
    temp = a;
    a = c;
    c = temp;
  }
  if (b < c) {
    temp = b;
    b = c;
    c = temp;
  }
}