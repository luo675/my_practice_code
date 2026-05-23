#include <iostream>

using namespace std;

class CTollBooth {
 private:
  int total_toll = 0;
  int total_uncharged = 0;
  int total_money = 0;

 public:
  void payingCar(int a) {
    ++total_toll;
    total_money += a;
  }
  void noPayCar() { ++total_uncharged; }
  void display() {
    cout << total_toll << " " << total_uncharged << " " << total_money << endl;
  }
};

int main() {
  int t;
  if (!(cin >> t)) return 0;
  CTollBooth text;
  while (t--) {
    char ch;
    cin >> ch;
    switch (ch) {
      case 'S': {
        text.noPayCar();
        break;
      }
      case 'C': {
        text.payingCar(5);
        break;
      }
      case 'V': {
        text.payingCar(8);
        break;
      }
      default:
        break;
    }
    text.display();
  }

  return 0;
}