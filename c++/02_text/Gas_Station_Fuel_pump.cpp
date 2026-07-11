#include <iostream>
using namespace std;
class Pump {
  double quantity;
  double price;
  /********** Write your code here! **********/
 public:
  void inputdata() { cin >> quantity >> price; }
  void outputdata() { cout << quantity << " " << price << endl; }
  int judge() {
    if (quantity == 0.0) {
      cout << "empty" << endl;
      return 0;
    } else
      return 1;
  }
  void cal(double want) {
    if (want <= quantity) {
      double money = want * price;
      cout << want << " " << money << endl;
      quantity = quantity - want;
    } else {
      double money = quantity * price;
      cout << quantity << " " << money << endl;
      quantity = 0;
    }
  }
};

int main() {
  Pump pum;
  pum.inputdata();
  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    double want;
    cin >> want;
    if (!pum.judge()) {
      return 0;
    }
    cout << "before: ";
    pum.outputdata();
    pum.cal(want);
    cout << "after: ";
    pum.outputdata();
    cout << endl;
  }

  /*******************************************/
  return 0;
}