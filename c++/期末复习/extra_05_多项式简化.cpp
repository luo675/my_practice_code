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

// ========== 你的代码 ==========




// ========== 代码结束 ==========

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
