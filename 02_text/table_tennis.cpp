#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_score(const string& s, int limit) {
  int a = 0, b = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'W')
      ++a;
    else
      ++b;
    if ((a >= limit || b >= limit) && abs(a - b) >= 2) {
      cout << a << ":" << b << endl;
      a = 0, b = 0;
    }
  }
  cout << a << ":" << b << endl;
}

int main() {
  string text = "";
  char ch;
  while (cin >> ch && ch != 'E') {
    if (ch == 'W' || ch == 'L') text += ch;
  }

  print_score(text, 11);
  cout << endl;
  print_score(text, 21);

  return 0;
}