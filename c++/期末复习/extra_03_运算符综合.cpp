/*
 * 附加题3：复数类（运算符重载综合）⭐ 考试高频
 *
 * 题目描述：
 * 实现 Complex 类（复数：实部real + 虚部imag）
 *
 * 要求：
 * 1. 友元 + 重载：两复数相加
 * 2. 友元 << 重载：输出格式 a+bi 或 a-bi
 * 3. 成员 ++ 前置：实部+1，虚部+1
 * 4. 成员 == 重载：判断两复数是否相等
 *
 * 预期输出：
 * 3+4i
 * 4+5i
 * not equal
 */
#include <iostream>
using namespace std;

// ========== 你的代码 ==========




// ========== 代码结束 ==========

int main() {
    Complex c1(1, 2), c2(2, 2);

    Complex c3 = c1 + c2;
    cout << c3 << endl;         // 3+4i

    ++c3;
    cout << c3 << endl;         // 4+5i

    Complex c4(4, 5);
    if (c3 == c4)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}
