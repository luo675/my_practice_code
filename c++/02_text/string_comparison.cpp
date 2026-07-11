#include <cstring>
#include <iostream>

using namespace std;

int judge(char* S, char* T) {
  int a = 0, b = 0;
  while (*S != '\0') {
    if (*S > *T)
      ++a;
    else if (*S < *T)
      ++b;
    ++S, ++T;
  }
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    char S[1000], T[1000];
    cin >> S >> T;
    if (strlen(S) > strlen(T))
      cout << "1" << endl;
    else if (strlen(S) < strlen(T))
      cout << "-1" << endl;
    else
      cout << judge(S, T) << endl;
  }

  return 0;
}