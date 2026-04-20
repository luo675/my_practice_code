#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int* p = arr;
    for (int i = 1; i < n; ++i) {
      if (*p < arr[i]) *p = arr[i];
    }
    cout << *p << endl;
    delete[] arr;
  }

  return 0;
}