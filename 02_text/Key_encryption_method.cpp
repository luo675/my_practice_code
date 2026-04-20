#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    char a[100], b[100], c[100];
    cin >> a >> b;
    char *p = a, *q = b, *s = c;
    while (*p != '\0') {
      if (*q == '\0') q = b;
      if (*p >= 'a' && *p <= 'z') {
        *s = (*p - 'a' + *q - '0') % 26 + 'a';
      } else if (*p >= 'A' && *p <= 'Z') {
        *s = (*p - 'A' + *q - '0') % 26 + 'A';
      }

      ++q;
      ++p;
      cout << *s;
      ++s;
      *s = '\0';
    }
    cout << endl;
  }

  return 0;
}