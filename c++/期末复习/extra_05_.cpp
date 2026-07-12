/*
 * 附加题5：单项式解析（模拟题⑤的简化版，攻克你的薄弱点）
 *
 * 题目描述：
 * 单项式格式：ax^b  （系数×x的指数），例如 "3x^2" 系数=3 指数=2
 *                          "x^3"   系数=1 指数=3
 *                          "5"     系数=5 指数=0
 *                          "-2x"   系数=-2 指数=1
 *
 * 1. 定义 Monomial 类，私有成员：系数 coef（int）、指数 exp（int）
 * 2. 实现友元函数 Monomial parse(string s)
 *    ——解析字符串 s，返回 Monomial 对象
 * 3. 重载 << 输出单项式
 *
 * 预期输出：
 * 3x^2
 * x^3
 * 5
 * -2x
 */
#include <iostream>
#include <string>
using namespace std;

// 第一步：先把整个类写完，编译器先认识Monomial
class Monomial {
 private:
  int coef;
  int exp;

 public:
  // 无参构造
  Monomial() : coef(0), exp(0) {}
  // 双参构造（刚才缺的核心）
  Monomial(int c, int e) : coef(c), exp(e) {}

  // 友元声明
  friend Monomial parse(string s);

  // 输出重载
  friend ostream& operator<<(ostream& os, const Monomial& m) {
    if (m.coef == 0) {
      os << 0;
      return os;
    }
    if (m.coef == 1 && m.exp > 0) {
    } else if (m.coef == -1 && m.exp > 0) {
      os << "-";
    } else {
      os << m.coef;
    }
    if (m.exp == 1) {
      os << "x";
    } else if (m.exp > 1) {
      os << "x^" << m.exp;
    }
    return os;
  }
};

// 第二步：类已经定义完了，再写parse，编译器完全认识Monomial
Monomial parse(string s) {
  int len = s.length();
  int x_pos = -1;
  for (int i = 0; i < len; i++) {
    if (s[i] == 'x') {
      x_pos = i;
      break;
    }
  }

  // 没有x（比如"5"）
  if (x_pos == -1) {
    int c = s[0] - '0';
    if (len == 2 && s[0] == '-') {
      c = -(s[1] - '0');
    }
    return Monomial(c, 0);
  }

  // 有x的情况
  int c = 1;
  if (x_pos == 0) {
    c = 1;
  } else if (x_pos == 1 && s[0] == '-') {
    c = -1;
  } else {
    c = s[0] - '0';
    if (s[0] == '-') {
      c = -(s[1] - '0');
    }
  }

  int e = 1;
  if (x_pos + 1 < len && s[x_pos + 1] == '^') {
    e = s[x_pos + 2] - '0';
  }

  return Monomial(c, e);
}

// 第三步：最后写main
int main() {
  Monomial m1 = parse("3x^2");
  Monomial m2 = parse("x^3");
  Monomial m3 = parse("5");
  Monomial m4 = parse("-2x");

  cout << m1 << endl;
  cout << m2 << endl;
  cout << m3 << endl;
  cout << m4 << endl;

  return 0;
}