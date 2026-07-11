#include <iostream>
#include <string>

using namespace std;

class Account {
 private:
  static int count;
  static float InterestRate;
  string _accno, _accname;
  float _balance;

 public:
  Account(string accno, string name, float balance);
  ~Account();
  void Deposit(float amount);
  void Withdraw(float amount);
  float GetBalance();
  void Show();
  static int GetCount();
  static float GetInterestRate();
  friend void Update(Account& a);
  static void SetInterestRate(float rate);
};
float Account::InterestRate = 0;
int Account::count = 0;

Account::Account(string accno, string name, float balance) {
  _accno = accno;
  _accname = name;
  _balance = balance;
  count++;
}

Account::~Account() {}

void Account::Deposit(float amount) { _balance += amount; }

void Account::Withdraw(float amount) {
  _balance -= amount;
  cout << _balance << endl;
}

float Account::GetBalance() { return _balance; }

void Account::Show() {
  cout << _accno << " " << _accname << " " << _balance << " ";
}

int Account::GetCount() { return count; }

float Account::GetInterestRate() { return InterestRate; }

void Update(Account& a) {
  a._balance += a.GetBalance() * Account::GetInterestRate();
  cout << a.GetBalance() << " ";
}

void Account::SetInterestRate(float rate) { InterestRate = rate; }

int main() {
  float interes;
  cin >> interes;
  Account::SetInterestRate(interes);
  int n;
  if (!(cin >> n)) return 0;
  float total = 0;
  Account** p = new Account*[n];
  for (int i = 0; i < n; ++i) {
    string acco, name;
    float in, out, bal;
    cin >> acco >> name >> bal >> in >> out;
    p[i] = new Account(acco, name, bal);
    p[i]->Deposit(in);
    p[i]->Show();
    Update(*p[i]);
    p[i]->Withdraw(out);
    total += p[i]->GetBalance();
  }
  for (int i = 0; i < n; ++i) {
    delete p[i];
  }
  delete[] p;
  cout << total << endl;
  return 0;
}