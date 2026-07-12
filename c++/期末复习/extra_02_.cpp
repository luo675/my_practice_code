/*
 * 附加题2：形状面积计算（继承 + 多态 + 虚析构）⭐ 必考方向
 *
 * 题目描述：
 * 基类 Shape：纯虚函数 area()
 * 派生类 Circle：半径 radius，面积 = 3.14 * r * r
 * 派生类 Rectangle：宽 width、高 height，面积 = w * h
 *
 * 在 main 中创建 Shape* 数组，存放 Circle 和 Rectangle，
 * 用基类指针循环调用 area()，最后 delete。
 *
 * 预期输出：
 * Circle area: 78.5
 * Rectangle area: 24
 */
#include <iostream>
using namespace std;

// ========== 你的代码 ==========




// ========== 代码结束 ==========

int main() {
    Shape* shapes[2];
    shapes[0] = new Circle(5);        // 半径5
    shapes[1] = new Rectangle(6, 4);  // 宽6 高4

    for (int i = 0; i < 2; i++) {
        shapes[i]->printArea();
    }

    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}
