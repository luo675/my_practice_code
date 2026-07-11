#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class CComplex {
 private:
  double real;
  double unreal;

 public:
  CComplex() : real(0), unreal(0) {}
  CComplex(double r, double ur) : real(r), unreal(ur) {}
  double getr() const { return real; }
  double getur() const { return unreal; }
};

template <typename T>
void disp_reverse(T t) {
  ostringstream os;
  string s;
  os << t;
  s = os.str();

  int index = 0;
  int n = s.length();

  if (s[0] == '-') {
    index = 1;
  }

  if (index == 1) {
    cout << "-";
  }
  int x = 0;  // 代表之前会输出的都是0
  for (int i = n - 1; i >= index; --i) {
    if (s[i] == '0' && x == 0) {
    } else {
      x = 1;
      cout << s[i];
    }
  }
  if (x == 0) cout << 0;
  cout << endl;
}

template <>
void disp_reverse<CComplex>(CComplex t) {
  cout << t.getur();
  double r = t.getr();
  if (r >= 0) {
    cout << "+";
  }
  cout << r << endl;
}

int main() {
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    char c;
    cin >> c;

    if (c == 'I') {
      int s;
      cin >> s;

      disp_reverse<int>(s);
    } else if (c == 'D') {
      double s;
      cin >> s;

      disp_reverse<double>(s);
    } else if (c == 'S') {
      string s;
      cin >> s;

      disp_reverse<string>(s);
    } else if (c == 'C') {
      double r, ur;
      cin >> r >> ur;
      CComplex s(r, ur);

      disp_reverse<CComplex>(s);
    }
  }

  return 0;
}