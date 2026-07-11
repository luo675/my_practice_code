#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  int L, R;
  cin >> L >> R;
  int sum = 0;
  for (int i = L - 1; i <= R - 1; ++i) {
    sum += arr[i];
  }
  cout << sum << endl;
  delete[] arr;
}