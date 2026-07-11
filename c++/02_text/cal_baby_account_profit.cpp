// 补齐头文件 及要求的类
/********** Write your code here! **********/
#include <iostream>
#include <string>

using namespace std;

class CPeople {
 protected:
  string id;
  string name;

 public:
  CPeople() {}
  CPeople(string i, string n) : id(i), name(n) {}
};

class CInternetUser : virtual public CPeople {
 protected:
  string password;

 public:
  CInternetUser() {}
  CInternetUser(string n, string i, string p) : CPeople(i, n), password(p) {}
  void registerUser(string n, string i, string p) {
    id = i;
    name = n;
    password = p;
  }
  bool virtual login(string i, string p) {
    if (i == id && p == password)
      return true;
    else
      return false;
  }
};

class CBankCustomer : virtual public CPeople {
 protected:
  double balance;

 public:
  CBankCustomer() { balance = 0; }
  void openAccount(string n, string i) {
    id = i;
    name = n;
  }
  void deposit(double m) { balance += m; }
  bool withdraw(double m) {
    if (m > balance) {
      return false;
    } else {
      balance -= m;
      return true;
    }
  }
};

class CInternetBankCustomer : public CInternetUser, public CBankCustomer {
 protected:
  double bal;
  double bal_yes;
  double profit_tod;
  double profit_tod_w;
  double profit_yes_w;

 public:
  CInternetBankCustomer() {
    bal = 0;
    bal_yes = 0;
    profit_tod_w = 0;
  }
  bool deposit(double m) {
    if (m > balance)
      return false;
    else {
      balance -= m;
      bal += m;
      return true;
    }
  }
  bool withdraw(double m) {
    if (m > bal)
      return false;
    else {
      bal -= m;
      balance += m;
      return true;
    }
  }
  void setInterest(double m) { profit_tod_w = m; }
  void calculateProfit() {
    profit_tod = bal_yes * profit_yes_w / 10000.0;
    bal_yes = bal + profit_tod;
    bal = bal + profit_tod;
    profit_yes_w = profit_tod_w;
  }
  bool login(string i, string p) {
    if (i == id && p == password)
      return true;
    else
      return false;
  }
  void print() {
    cout << "Name: " << name << " ID: " << id << endl;
    cout << "Bank balance: " << balance << endl;
    cout << "Internet bank balance: " << bal << endl;
    cout << endl;
  }
};

/*******************************************/
int main() {
  int t, no_of_days, i;
  string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
  double money, interest;
  char op_code;

  // 输入测试案例数t
  cin >> t;
  while (t--) {
    // 输入互联网用户注册时的用户名,id,登陆密码
    cin >> i_xm >> i_id >> i_mm;

    // 输入银行开户用户名,id
    cin >> b_xm >> b_id;

    // 输入互联网用户登陆时的id,登陆密码
    cin >> ib_id >> ib_mm;

    CInternetBankCustomer ib_user;

    ib_user.registerUser(i_xm, i_id, i_mm);
    ib_user.openAccount(b_xm, b_id);

    if (ib_user.login(ib_id, ib_mm) ==
        0)  // 互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
    {
      cout << "Password or ID incorrect" << endl;
      continue;
    }

    // 输入天数
    cin >> no_of_days;
    for (i = 0; i < no_of_days; i++) {
      // 输入操作代码, 金额, 当日万元收益
      cin >> op_code >> money >> interest;
      switch (op_code) {
        case 'S':  // 从银行向互联网金融帐户存入
        case 's':
          if (ib_user.deposit(money) == 0) {
            cout << "Bank balance not enough" << endl;
            continue;
          }
          break;
        case 'T':  // 从互联网金融转入银行帐户
        case 't':
          if (ib_user.withdraw(money) == 0) {
            cout << "Internet bank balance not enough" << endl;
            continue;
          }
          break;
        case 'D':  // 直接向银行帐户存款
        case 'd':
          ib_user.CBankCustomer::deposit(money);
          break;
        case 'W':  // 直接从银行帐户取款
        case 'w':
          if (ib_user.CBankCustomer::withdraw(money) == 0) {
            cout << "Bank balance not enough" << endl;
            continue;
          }
          break;
        default:
          cout << "Illegal input" << endl;
          continue;
      }
      ib_user.setInterest(interest);
      ib_user.calculateProfit();
      // 输出用户名,id
      // 输出银行余额
      // 输出互联网金融账户余额
      ib_user.print();
    }
  }
}
