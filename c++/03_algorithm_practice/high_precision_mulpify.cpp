#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 5010;
int a[maxn], b[maxn], c[maxn];

void mul(const string& A, const string& B) {
  fill(a, a + maxn, 0);
  fill(b, b + maxn, 0);
  fill(c, c + maxn, 0);

  int lena = A.size(), lenb = B.size();

  for (int i = lena - 1; i >= 0; i--) a[lena - i] = A[i] - '0';

  for (int i = lenb - 1; i >= 0; i--) b[lenb - i] = B[i] - '0';

  for (int i = 1; i <= lena; i++)
    for (int j = 1; j <= lenb; j++) c[i + j - 1] += a[i] * b[j];

  int len = lena + lenb;
  for (int i = 1; i <= len; i++) {
    c[i + 1] += c[i] / 10;
    c[i] %= 10;
  }
}

int main() {
  string A, B;
  cin >> A >> B;

  mul(A, B);

  int len = A.size() + B.size();
  while (len > 1 && !c[len]) len--;

  for (int i = len; i >= 1; i--) cout << c[i];

  return 0;
}