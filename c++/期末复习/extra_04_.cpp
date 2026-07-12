/*
 * 附加题4：通用数组类（类模板 + 函数模板）⭐ 必考
 *
 * 题目描述：
 * 1. 写一个函数模板 swapAny，交换两个同类型变量的值
 * 2. 写一个类模板 MyArray<T>，包含：
 *    - 构造函数：传入大小，new 分配数组
 *    - 析构函数：delete[] 释放
 *    - 拷贝构造：深拷贝
 *    - operator[]：返回引用
 *    - print()：输出所有元素，空格分隔
 *
 * 预期输出：
 * 1 2 3 4 5
 * 3.5 7.2 1.8
 * swapAny: 20 10
 */
#include <iostream>
using namespace std;

// ========== 你的代码 ==========




// ========== 代码结束 ==========

int main() {
    // 测试 MyArray<int>
    int raw[] = {1, 2, 3, 4, 5};
    MyArray<int> arr(5);
    for (int i = 0; i < 5; i++) arr[i] = raw[i];
    arr.print();  // 1 2 3 4 5

    // 测试 MyArray<double>
    MyArray<double> arr2(3);
    arr2[0] = 3.5; arr2[1] = 7.2; arr2[2] = 1.8;
    arr2.print();  // 3.5 7.2 1.8

    // 测试 swapAny
    int x = 10, y = 20;
    swapAny(x, y);
    cout << "swapAny: " << x << " " << y << endl;  // 20 10

    return 0;
}
