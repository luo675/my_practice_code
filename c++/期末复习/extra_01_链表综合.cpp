/*
 * 附加题1：学生成绩链表（链表 + 类封装）⭐ 必考方向
 *
 * 题目描述：
 * 定义 Student 结构体（学号id、姓名name、成绩score）
 * 用链表管理学生信息，实现以下功能：
 * 1. 按成绩从高到低插入（insertSorted）——插入时自动排序
 * 2. 打印所有学生信息
 * 3. 删除成绩低于60分的学生
 * 4. 析构释放所有节点
 *
 * main函数测试数据：
 * 插入(1001,"Alice",85)、(1002,"Bob",55)、(1003,"Tom",92)、(1004,"Jerry",45)
 *
 * 预期输出：
 * 所有学生:
 * 1003 Tom 92
 * 1001 Alice 85
 * 1002 Bob 55
 * 1004 Jerry 45
 * 删除不及格后:
 * 1003 Tom 92
 * 1001 Alice 85
 */
#include <iostream>
#include <string>
using namespace std;

// ========== 你的代码 ==========




// ========== 代码结束 ==========

int main() {
    ScoreList list;

    list.insertSorted(1001, "Alice", 85);
    list.insertSorted(1002, "Bob",   55);
    list.insertSorted(1003, "Tom",   92);
    list.insertSorted(1004, "Jerry", 45);

    cout << "所有学生:" << endl;
    list.print();

    list.removeFailed();  // 删除不及格
    cout << "删除不及格后:" << endl;
    list.print();

    return 0;
}
