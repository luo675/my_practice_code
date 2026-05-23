#include <iostream>

using namespace std;

void swap(int* a, int* b) {
  int* temp;
  temp = a;
  a = b;
  b = a;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    swap(a, b);
    cout << a << " " << b << endl;
  }

  return 0;
}