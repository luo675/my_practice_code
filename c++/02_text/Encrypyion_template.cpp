#include <iostream>
#include <string>

using namespace std;

template <typename T>
T Max(T tt[], int tl) {
  T m = tt[0];
  for (int i = 1; i < tl; i++) {
    if (tt[i] > m) {
      m = tt[i];
    }
  }

  return m;
}

template <typename T>
class Cryption {
 private:
  T ptxt[100];
  T ctxt[100];
  T key;
  int len;

 public:
  Cryption(T tk, T tt[], int tl) : key(tk), len(tl) {
    for (int i = 0; i < tl; ++i) {
      ptxt[i] = tt[i];
    }
  }
  void Encrypt() {
    T m = Max(ptxt, len);
    T pian[100];
    for (int i = 0; i < len; i++) {
      pian[i] = m - ptxt[i];
    }
    for (int i = 0; i < len; i++) {
      ctxt[i] = key + pian[i];
    }
  }
  void Print() {
    int i;
    for (i = 0; i < len - 1; i++) {
      cout << ctxt[i] << " ";
    }
    cout << ctxt[i] << endl;
  }
};

int main() {
  int i;
  int length;
  int ik, itxt[100];
  double dk, dtxt[100];
  char ck, ctxt[100];

  cin >> ik >> length;
  for (int i = 0; i < length; i++) {
    cin >> itxt[i];
  }

  Cryption<int> ic(ik, itxt, length);
  ic.Encrypt();
  ic.Print();

  cin >> dk >> length;
  for (int i = 0; i < length; i++) {
    cin >> dtxt[i];
  }
  Cryption<double> dc(dk, dtxt, length);
  dc.Encrypt();
  dc.Print();

  cin >> ck >> length;
  for (int i = 0; i < length; i++) {
    cin >> ctxt[i];
  }
  Cryption<char> cc(ck, ctxt, length);
  cc.Encrypt();
  cc.Print();

  return 0;
}
