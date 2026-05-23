#include <iostream>
#include <string>

using namespace std;

class CPerson {
 protected:
  string name;
  string phone;

 public:
  CPerson(string na, string ph) : name(na), phone(ph) {}
  virtual ~CPerson() {}  // 良好的习惯：虚析构
};

class stu : public CPerson {
 protected:
  int Atime[12];

 public:
  stu(string na, string ph, int a[12]) : CPerson(na, ph) {
    for (int i = 0; i < 12; ++i) Atime[i] = a[i];
  }

  virtual void check() {
    int total = 0;
    for (int i = 0; i < 12; ++i) {
      // A场地：一天最多1个学时
      if (Atime[i] >= 60) {
        total += 1;
      }
    }
    printResult(total);
  }

  // 提取公共打印逻辑，防止格式错误
  void printResult(int total) {
    cout << name;
    if (total >= 10) {
      cout << "达到学时要求可以预约！";
    } else {
      cout << "未达到学时要求不能预约！";
    }
    cout << "电话" << phone << endl;
  }
};

class stuVIP : public stu {
 protected:
  int Btime[12];

 public:
  stuVIP(string na, string ph, int a[12], int b[12]) : stu(na, ph, a) {
    for (int i = 0; i < 12; ++i) Btime[i] = b[i];
  }

  void check() override {
    int total = 0;
    for (int i = 0; i < 12; ++i) {
      // A场地学时计算
      int a_hour = (Atime[i] >= 60 ? 1 : 0);

      // B场地学时计算：最多2学时
      int b_hour = 0;
      if (Btime[i] >= 120)
        b_hour = 2;
      else if (Btime[i] >= 60)
        b_hour = 1;

      total += (a_hour + b_hour);
    }
    printResult(total);
  }
};

int main() {
  // 解决你之前的乱码问题，建议在本地环境执行，OJ上通常不需要
  // system("chcp 65001");

  int t;
  if (!(cin >> t)) return 0;
  while (t--) {
    string type, name, phone;
    cin >> type >> name >> phone;
    int a[12], b[12];
    if (type == "F") {
      for (int i = 0; i < 12; ++i) cin >> a[i];
      stu s1(name, phone, a);
      s1.check();
    } else {
      for (int i = 0; i < 12; ++i) cin >> a[i];
      for (int i = 0; i < 12; ++i) cin >> b[i];
      stuVIP s2(name, phone, a, b);
      s2.check();
    }
  }
  return 0;
}