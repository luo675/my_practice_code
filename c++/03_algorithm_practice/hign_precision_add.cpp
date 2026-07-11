#include <algorithm>
#include <iostream>
#include <string>
#define maxn 520

using namespace std;

int a[maxn] = {0}, b[maxn] = {0}, c[maxn] = {0};

void high_precision_add(string A, string B, int len) {
  for (int i = 0; i < maxn; i++) {
    c[i] = 0;
  }

  for (int i = A.length() - 1, j = 1; i >= 0; i--, j++) {
    a[j] = A[i] - '0';
  }
  for (int i = B.length() - 1, j = 1; i >= 0; i--, j++) {
    b[j] = B[i] - '0';
  }

  for (int i = 1; i <= len; i++) {
    c[i] += a[i] + b[i];
    c[i + 1] += c[i] / 10;
    c[i] %= 10;
  }
}

int main() {
  string A, B;
  cin >> A >> B;
  int len = max(A.length(), B.length());
  high_precision_add(A, B, len);
  if (c[len + 1]) {
    len++;
  }
  for (int i = len; i >= 1; --i) {
    cout << c[i];
  }
  cout << endl;

  return 0;
}