#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  if (s[0] != '+' && s[0] != '-') {
    s = "+" + s;
  }

  int i = 0;
  while (i < s.size()) {
    char sign = s[i];
    i++;

    string s1 = "";

    while (i < s.size() && isdigit(s[i])) {
      s1 += s[i];
      i++;
    }

    int n;

    if (s1.empty()) {
      n = 1;
    } else {
      n = stoi(s1);
    }

    if (sign == '-') n = -n;

    int exp = 0;
    if (i < s.size() && s[i] == 'x') {
      exp = 1;
      i++;
      if (i < s.size() && s[i] == '^') {
        i++;
        string s2 = "";
        while (i < s.size() && isdigit(s[i])) {
          s2 += s[i];
          i++;
        }
        exp = stoi(s2);
      }
    }

    cout << n << " " << exp << endl;
  }

  return 0;
}