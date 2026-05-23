#include <cmath>
#include <iostream>

using namespace std;

int I(int a) { return a * a; }

float F(float a) { return sqrt(a); }

void S(char* a) {
  while (*a != '\0') {
    if ((*a) >= 'a' && (*a) <= 'z') {
      *a = *a - 'a' + 'A';
    }
    ++a;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    char ch;
    cin >> ch;
    switch (ch) {
      case 'I': {
        int a;
        cin >> a;
        int (*p)(int);
        p = I;
        int b = (*p)(a);
        cout << b << endl;
        break;
      }
      case 'F': {
        float a;
        cin >> a;
        float (*p)(float);
        p = F;
        float b = (*p)(a);
        cout << b << endl;
        break;
      }
      case 'S': {
        char text[1000];
        cin >> text;
        void (*p)(char*);
        p = S;
        (*p)(text);
        cout << text << endl;
        break;
      }
      default:
        break;
    }
  }
  return 0;
}