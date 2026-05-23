#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int *d = &a, *e = &b, *f = &c;
    int* temp = 0;
    if (*d < *e) {
      temp = d;
      d = e;
      e = temp;
    }
    if (*d < *f) {
      temp = d;
      d = f;
      f = temp;
    }
    if (*f > *e) {
      temp = f;
      f = e;
      e = temp;
    }
    cout << *d << " " << *e << " " << *f << " " << endl;
  }

  return 0;
}