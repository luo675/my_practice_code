#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  double D = 6.2619, E = 6.6744, Y = 0.0516, H = 0.8065;
  const double* p = nullptr;
  while (t--) {
    char ch;
    cin >> ch;
    double money;
    cin >> money;
    switch (ch) {
      case 'D': {
        p = &D;
        break;
      }
      case 'E': {
        p = &E;
        break;
      }
      case 'Y': {
        p = &Y;
        break;
      }
      case 'H': {
        p = &H;
        break;
      }
      default:
        break;
    }
    double RMB = *p * money;
    cout << fixed << setprecision(4) << RMB << endl;
  }

  return 0;
}