// 头文件区域
#include <iostream>
using namespace std;
// 填空区域1：类CDate的定义
/********** Write your code here! **********/
class CDate {
 private:
  int y;
  int m;
  int d;

 public:
  CDate(int d, int m, int y) : y(y), m(m), d(d) {}
  ~CDate() {};
  CDate(const CDate& other) {
    y = other.y;
    m = other.m;
    d = other.d;
    add_one();
  }

  void add_one() {
    d++;
    if (m == 2) {
      int a = judge();
      if (a == 1) {  // 是闰年
        if (d == 30) {
          d = 1;
          m++;
        }
      } else {  // 不是闰年
        if (d == 29) {
          d = 1;
          m++;
        }
      }
    }

    else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) {
      if (d == 32) {
        d = 1;
        m++;
      }
    }

    else if (m == 4 || m == 6 || m == 9 || m == 11) {
      if (d == 31) {
        d = 1;
        m++;
      }
    }

    else {  // m=12
      if (d == 32) {
        m = 1;
        y++;
        d = 1;
      }
    }
  }

  int judge() {  // 判断是不是闰年
    if (y % 4 == 0) {
      if (y % 100 != 0) {
        return 1;
      } else {
        if (y % 400 == 0) {
          return 1;
        } else
          return 0;
      }
    } else
      return 0;
  }

  void print() { cout << y << "/" << m << "/" << d << endl; }
};

/*******************************************/
// 主函数区域
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  CDate d1(a, b, c);
  CDate d2 = d1;
  CDate d3(d2);
  d1.print();
  d2.print();
  d3.print();
  return 0;
}
