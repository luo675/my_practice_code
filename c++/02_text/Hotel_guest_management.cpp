#include <cstring>
#include <iostream>

using namespace std;

class Customer {
 private:
  static int TotalCustNum;
  static int Rent;
  static int Year;
  int CusID;
  char* CustName;

 public:
  Customer(char* name) {
    TotalCustNum++;
    CusID = TotalCustNum;

    CustName = new char[strlen(name) + 1];
    strcpy(CustName, name);
  }
  ~Customer() {
    if (CustName) {
      delete[] CustName;
      CustName = NULL;
    }
  }

  static void changeYear(int r) { Year = r; }

  void Display() {
    cout << CustName << " " << Year;
    if (CusID < 10) {
      cout << "000";
    } else if (CusID < 100 && CusID >= 10) {
      cout << "00";
    } else if (CusID < 1000 && CusID >= 100) {
      cout << "0";
    }
    cout << CusID << " " << CusID << " " << Rent * CusID << endl;
  }
};

int Customer::TotalCustNum = 0;
int Customer::Rent = 150;
int Customer::Year = 2014;

int main() {
  int t;
  if (!(cin >> t)) return 0;

  while (t--) {
    int year;
    cin >> year;
    Customer::changeYear(year);
    char name[1000];
    while (cin >> name && strcmp(name, "0") != 0) {
      Customer cus(name);
      cus.Display();
    }
  }

  return 0;
}